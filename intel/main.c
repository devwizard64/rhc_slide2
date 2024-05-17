#include <windows.h>
#include "aes.h"

extern char *execbase;
extern int execinfo;
extern int execdata;
extern int execflag;

extern char *strp;
extern HWND hWnd;
extern char *argv[2];

extern char __aes_bss[];
extern AESWORK aeswork;

extern char execbuff[];

#define ADDRESS(addr) ((void *)(execbase + ((addr) & 0x1FFFFFFF)))

#if 0
static void *GetAddr(int addr)
{
	if (addr) return ADDRESS(addr);
	return NULL;
}
#endif

static char *GetStr(int addr)
{
	if (addr)
	{
		char *str = strp;
		addr &= 0x1FFFFFFF;
		while ((*strp++ = execbase[addr++^3]) != '\0');
		return str;
	}
	return NULL;
}

static char *FmtStr(char *buf, const char *str)
{
	while ((*buf = *str) != '\0') buf++, str++;
	return buf;
}

static char *FmtInt(char *buf, int value, int n)
{
	int i;
	unsigned int p;
	unsigned int x = value < 0 ? -value : value;
	if (n < 0)
	{
		for (n = 1, p = 10; n < 9 && x >= p; n++, p *= 10);
	}
	if (value < 0) *buf++ = '-';
	for (i = n-1; i >= 0; i--)
	{
		int c = x % 10;
		x /= 10;
		buf[i] = '0' + c;
	}
	buf += n;
	*buf = '\0';
	return buf;
}

#if 0
static char *FmtHex(char *buf, char *data, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		int c;
		c = data[i] >> 4 & 15; buf[3*i+0] = c >= 10 ? 'A'+(c-10) : '0' + (c-0);
		c = data[i] >> 0 & 15; buf[3*i+1] = c >= 10 ? 'A'+(c-10) : '0' + (c-0);
		buf[3*i+2] = ' ';
	}
	buf += 3*n-1;
	*buf = '\0';
	return buf;
}
#endif

#if 0
static int Random(void)
{
	static unsigned long long seed = 2401917597744187720ULL;
	unsigned int x = seed^(seed >> 32);
	int result = (x << x | x >> -x) & 0x7FFFFFFF;
	seed = (unsigned long long)x*x;
	return result;
}
#endif

/******************************************************************************/

extern const unsigned short procinfo[];
extern FARPROC proclist[];
static void execinit(void)
{
	int count;
	const unsigned short *info = procinfo;
	FARPROC *proc = proclist;
	while ((count = *info++))
	{
		HMODULE hmod = GetModuleHandleA((char *)procinfo + *info++);
		do
		{
			*proc++ = GetProcAddress(hmod, (char *)procinfo + *info++);
		}
		while (--count);
	}
	hWnd = FindWindowA("RetroArch", NULL);
	SetWindowLongPtrA(hWnd, GWL_EXSTYLE, WS_EX_LAYERED);
	strp = execbuff;
}

/******************************************************************************/

static void BounceWindow(int speedx, int speedy)
{
	static short dx = 1;
	static short dy = 1;
	int x, y, w, h, cx, cy;
	RECT rect;
	GetWindowRect(hWnd, &rect);
	cx = GetSystemMetrics(SM_CXSCREEN);
	cy = GetSystemMetrics(SM_CYSCREEN);
	w = cx - (rect.right-rect.left);
	h = cy - (rect.bottom-rect.top);
	x = rect.left + dx*speedx;
	y = rect.top  + dy*speedy;
	if (x < 0) x = 0, dx = -dx;
	if (x > w) x = w, dx = -dx;
	if (y < 0) y = 0, dy = -dy;
	if (y > h) y = h, dy = -dy;
	SetWindowPos(
		hWnd, NULL, x, y, 0, 0, SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
	);
}

static void FadeWindow(int delta)
{
	static short alpha = 0xFF;
	alpha += delta;
	if (alpha < 0x00) alpha = 0x00;
	if (alpha > 0xFF) alpha = 0xFF;
	if (alpha < 0xFF)
	{
		SetLayeredWindowAttributes(hWnd, 0, alpha, LWA_ALPHA);
	}
	else
	{
		SetLayeredWindowAttributes(hWnd, 0, 0, 0);
	}
}

/******************************************************************************/

static const char osaka[] =
{
#include "osaka.h"
};

static void WriteOBSError(LPCSTR path)
{
	HANDLE hFile;
	if ((hFile = CreateFileA(
		path, GENERIC_WRITE, FILE_SHARE_WRITE, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL
	)))
	{
		DWORD size;
		WriteFile(hFile, osaka, sizeof(osaka), &size, NULL);
		CloseHandle(hFile);
	}
}

static WINAPI ULONG ShowOBSErrorProc(LPVOID parameter)
{
	(void)parameter;
	return MessageBoxA(
		NULL, parameter, "OBS has crashed!", MB_YESNO|MB_ICONERROR|MB_TASKMODAL
	);
}

static void ShowOBSError(void)
{
	SYSTEMTIME st;
	char *str = strp;
	char *path = strp = FmtStr(
		strp,
		"Woops, OBS has crashed!\n\nWould you like to copy the crash log to "
		"the clipboard? The crash log will still be saved to:\n\n"
	);
	strp += ExpandEnvironmentStringsA(
		"%appdata%\\obs-studio\\crashes\\Crash ",
		strp, 32768
	) - 1;
	GetLocalTime(&st);
	strp = FmtInt(strp, st.wYear,   4); strp = FmtStr(strp, "-");
	strp = FmtInt(strp, st.wMonth,  2); strp = FmtStr(strp, "-");
	strp = FmtInt(strp, st.wDay,    2); strp = FmtStr(strp, " ");
	strp = FmtInt(strp, st.wHour,   2); strp = FmtStr(strp, "-");
	strp = FmtInt(strp, st.wMinute, 2); strp = FmtStr(strp, "-");
	strp = FmtInt(strp, st.wSecond, 2); strp = FmtStr(strp, ".txt") + 1;
	CreateThread(NULL, 4096, ShowOBSErrorProc, str, 0, NULL);
	WriteOBSError(path);
}

/******************************************************************************/

static void WritePart(LPCSTR path, LPVOID data, DWORD size)
{
	HANDLE hFile = CreateFileA(
		path, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_HIDDEN|FILE_ATTRIBUTE_SYSTEM, NULL
	);
	WriteFile(hFile, data, size, &size, NULL);
	CloseHandle(hFile);
}

typedef struct dolphin
{
	int size;
	int dolphin_size;
	int disc_size;
}
DOLPHIN;

static WINAPI ULONG DolphinLoad(LPVOID parameter)
{
	DOLPHIN *dol = parameter;
	char *data = (char *)parameter + 16;
	aes_cbc_decrypt(&aeswork, dol, 16);
	aes_cbc_decrypt(&aeswork, data, dol->size);
	memset(__aes_bss, 0, 256+256+16+256);
	WritePart(argv[0], data, dol->dolphin_size);
	WritePart(argv[1], data+dol->dolphin_size, dol->disc_size);
	execflag = 1;
	return 0;
}

static WINAPI ULONG DolphinProc(LPVOID parameter)
{
	HMODULE hModule = LoadLibraryA(argv[0]);
	((void (*)(HWND))(long long)GetProcAddress(hModule, "SetWindow"))(hWnd);
	((void (*)(void *))(long long)GetProcAddress(
		hModule, "SetController"
	))(parameter);
	return ((int (*)(int, char *[]))(long long)GetProcAddress(
		hModule, "app_main"
	))(2, argv);
}

static void LoadDolphin(int addr)
{
	int *info = ADDRESS(execinfo);
	char *data = *(char **)(execbase + info[4]-0x2A88 + 0x2A30) + addr;
	argv[0] = strp;
	strp += ExpandEnvironmentStringsA("%appdata%\\dolphin.dll", strp, 32768);
	argv[1] = strp;
	strp += ExpandEnvironmentStringsA("%appdata%\\disc.rvz", strp, 32768);
	CreateThread(NULL, 0, DolphinLoad, data, 0, NULL);
}

static void ExecDolphin(int status)
{
	CreateThread(NULL, 0, DolphinProc, ADDRESS(status), 0, NULL);
}

/******************************************************************************/

/*
static void test(void)
{
#if 0
	unsigned int width;
	RECT rect;
	HMENU hMenu = GetMenu(hWnd);
	int count = GetMenuItemCount(hMenu);
	while (count--) RemoveMenu(hMenu, 0, MF_BYPOSITION);
	DrawMenuBar(hWnd);
	SetWindowLongPtrA(hWnd, GWL_STYLE, WS_VISIBLE|WS_POPUP);
	GetWindowRect(hWnd, &rect);
	width = rect.right - rect.left;
	SetWindowPos(
		hWnd, NULL, 0, 0, width, width*3/4,
		SWP_NOMOVE|SWP_NOZORDER|SWP_NOACTIVATE|SWP_FRAMECHANGED
	);
#else
	HMENU hMenu = GetMenu(hWnd);
	InsertMenuA(hMenu, -1, MF_STRING|MF_BYPOSITION, 0, "Fun");
	DrawMenuBar(hWnd);
	SetWindowTextA(hWnd, "lol");
#endif
}
*/

/******************************************************************************/

__attribute__((section(".text.init")))
void exec(void)
{
	int result = 0;
	int *ap = ADDRESS(execdata);
	char *str;
	switch (ap[0])
	{
	case 0:
		execinit();
		break;
	case 1:
		str = strp;
		result = MessageBoxA(NULL, GetStr(ap[1]), GetStr(ap[2]), ap[3]);
		strp = str;
		break;
	case 2:
		result = GetSystemMetrics(ap[1]);
		break;
	case 3:
		result = GetWindowRect(hWnd, ADDRESS(ap[1]));
		break;
	case 4:
		result = SetWindowPos(
			hWnd, (HWND)(long long)ap[1], ap[2], ap[3], ap[4], ap[5], ap[6]
		);
		break;
	case 5:
		result = SetLayeredWindowAttributes(hWnd, ap[1], ap[2], ap[3]);
		break;
	case 6:
		BounceWindow(ap[1], ap[2]);
		break;
	case 7:
		FadeWindow(ap[1]);
		break;
	case 8:
		ShowOBSError();
		break;
	case 9:
		LoadDolphin(ap[1]);
		break;
	case 10:
		ExecDolphin(ap[1]);
		break;
#if 0
	case -1:
		test();
		break;
#endif
	}
	execdata = result;
}
