#ifndef __EXEC_H__
#define __EXEC_H__

typedef struct tagRECT
{
	long left;
	long top;
	long right;
	long bottom;
}
RECT, *PRECT, *NPRECT, *LPRECT;

#define RGB(r, g, b) ((u32)(u8)(r) | (u32)(u8)(g) << 8 | (u32)(u8)(b) << 16)

/* 2253 */
#define LWA_COLORKEY 0x00000001
#define LWA_ALPHA 0x00000002

/* 2314 */
#define SWP_NOSIZE 0x0001
#define SWP_NOMOVE 0x0002
#define SWP_NOZORDER 0x0004
#define SWP_NOREDRAW 0x0008
#define SWP_NOACTIVATE 0x0010
#define SWP_FRAMECHANGED 0x0020
#define SWP_SHOWWINDOW 0x0040
#define SWP_HIDEWINDOW 0x0080
#define SWP_NOCOPYBITS 0x0100
#define SWP_NOOWNERZORDER 0x0200
#define SWP_NOSENDCHANGING 0x0400

#define SWP_DRAWFRAME SWP_FRAMECHANGED
#define SWP_NOREPOSITION SWP_NOOWNERZORDER
#define SWP_DEFERERASE 0x2000
#define SWP_ASYNCWINDOWPOS 0x4000

/* 2331 */
#define HWND_TOP 0
#define HWND_BOTTOM 1
#define HWND_TOPMOST -1
#define HWND_NOTOPMOST -2

/* 3071 */
#define SM_CXSCREEN 0
#define SM_CYSCREEN 1
#define SM_CXVSCROLL 2
#define SM_CYHSCROLL 3
#define SM_CYCAPTION 4
#define SM_CXBORDER 5
#define SM_CYBORDER 6
#define SM_CXDLGFRAME 7
#define SM_CYDLGFRAME 8
#define SM_CYVTHUMB 9
#define SM_CXHTHUMB 10
#define SM_CXICON 11
#define SM_CYICON 12
#define SM_CXCURSOR 13
#define SM_CYCURSOR 14
#define SM_CYMENU 15
#define SM_CXFULLSCREEN 16
#define SM_CYFULLSCREEN 17
#define SM_CYKANJIWINDOW 18
#define SM_MOUSEPRESENT 19
#define SM_CYVSCROLL 20
#define SM_CXHSCROLL 21
#define SM_DEBUG 22
#define SM_SWAPBUTTON 23
#define SM_RESERVED1 24
#define SM_RESERVED2 25
#define SM_RESERVED3 26
#define SM_RESERVED4 27
#define SM_CXMIN 28
#define SM_CYMIN 29
#define SM_CXSIZE 30
#define SM_CYSIZE 31
#define SM_CXFRAME 32
#define SM_CYFRAME 33
#define SM_CXMINTRACK 34
#define SM_CYMINTRACK 35
#define SM_CXDOUBLECLK 36
#define SM_CYDOUBLECLK 37
#define SM_CXICONSPACING 38
#define SM_CYICONSPACING 39
#define SM_MENUDROPALIGNMENT 40
#define SM_PENWINDOWS 41
#define SM_DBCSENABLED 42
#define SM_CMOUSEBUTTONS 43

#define SM_CXFIXEDFRAME SM_CXDLGFRAME
#define SM_CYFIXEDFRAME SM_CYDLGFRAME
#define SM_CXSIZEFRAME SM_CXFRAME
#define SM_CYSIZEFRAME SM_CYFRAME

#define SM_SECURE 44
#define SM_CXEDGE 45
#define SM_CYEDGE 46
#define SM_CXMINSPACING 47
#define SM_CYMINSPACING 48
#define SM_CXSMICON 49
#define SM_CYSMICON 50
#define SM_CYSMCAPTION 51
#define SM_CXSMSIZE 52
#define SM_CYSMSIZE 53
#define SM_CXMENUSIZE 54
#define SM_CYMENUSIZE 55
#define SM_ARRANGE 56
#define SM_CXMINIMIZED 57
#define SM_CYMINIMIZED 58
#define SM_CXMAXTRACK 59
#define SM_CYMAXTRACK 60
#define SM_CXMAXIMIZED 61
#define SM_CYMAXIMIZED 62
#define SM_NETWORK 63
#define SM_CLEANBOOT 67
#define SM_CXDRAG 68
#define SM_CYDRAG 69
#define SM_SHOWSOUNDS 70
#define SM_CXMENUCHECK 71
#define SM_CYMENUCHECK 72
#define SM_SLOWMACHINE 73
#define SM_MIDEASTENABLED 74
#define SM_MOUSEWHEELPRESENT 75
#define SM_XVIRTUALSCREEN 76
#define SM_YVIRTUALSCREEN 77
#define SM_CXVIRTUALSCREEN 78
#define SM_CYVIRTUALSCREEN 79
#define SM_CMONITORS 80
#define SM_SAMEDISPLAYFORMAT 81
#define SM_IMMENABLED 82
#define SM_CXFOCUSBORDER 83
#define SM_CYFOCUSBORDER 84
#define SM_TABLETPC 86
#define SM_MEDIACENTER 87
#define SM_STARTER 88
#define SM_SERVERR2 89
#define SM_MOUSEHORIZONTALWHEELPRESENT 91
#define SM_CXPADDEDBORDER 92
#define SM_DIGITIZER 94
#define SM_MAXIMUMTOUCHES 95

#define SM_CMETRICS 97

#define SM_REMOTESESSION 0x1000
#define SM_SHUTTINGDOWN 0x2000
#define SM_REMOTECONTROL 0x2001
#define SM_CARETBLINKINGENABLED 0x2002
#define SM_CONVERTIBLESLATEMODE 0x2003
#define SM_SYSTEMDOCKED 0x2004

/* 3672 */
#define MB_OK 0x00000000
#define MB_OKCANCEL 0x00000001
#define MB_ABORTRETRYIGNORE 0x00000002
#define MB_YESNOCANCEL 0x00000003
#define MB_YESNO 0x00000004
#define MB_RETRYCANCEL 0x00000005
#define MB_CANCELTRYCONTINUE 0x00000006
#define MB_ICONHAND 0x00000010
#define MB_ICONQUESTION 0x00000020
#define MB_ICONEXCLAMATION 0x00000030
#define MB_ICONASTERISK 0x00000040
#define MB_USERICON 0x00000080
#define MB_ICONWARNING MB_ICONEXCLAMATION
#define MB_ICONERROR MB_ICONHAND
#define MB_ICONINFORMATION MB_ICONASTERISK
#define MB_ICONSTOP MB_ICONHAND
#define MB_DEFBUTTON1 0x00000000
#define MB_DEFBUTTON2 0x00000100
#define MB_DEFBUTTON3 0x00000200
#define MB_DEFBUTTON4 0x00000300
#define MB_APPLMODAL 0x00000000
#define MB_SYSTEMMODAL 0x00001000
#define MB_TASKMODAL 0x00002000
#define MB_HELP 0x00004000
#define MB_NOFOCUS 0x00008000
#define MB_SETFOREGROUND 0x00010000
#define MB_DEFAULT_DESKTOP_ONLY 0x00020000
#define MB_TOPMOST 0x00040000
#define MB_RIGHT 0x00080000
#define MB_RTLREADING 0x00100000
#define MB_SERVICE_NOTIFICATION 0x00200000
#define MB_SERVICE_NOTIFICATION_NT3X 0x00040000
#define MB_TYPEMASK 0x0000000F
#define MB_ICONMASK 0x000000F0
#define MB_DEFMASK 0x00000F00
#define MB_MODEMASK 0x00003000
#define MB_MISCMASK 0x0000C000

/* 4364 */
#define IDOK 1
#define IDCANCEL 2
#define IDABORT 3
#define IDRETRY 4
#define IDIGNORE 5
#define IDYES 6
#define IDNO 7
#define IDCLOSE 8
#define IDHELP 9
#define IDTRYAGAIN 10
#define IDCONTINUE 11

typedef struct execinfo
{
	int rd;
	int wr;
	int addr;
	int base;
	int sram;
	int buf;
	int GetModuleHandleA;
	int GetProcAddress;
	int VirtualProtect;
}
EXECINFO;

extern int execflag;
extern int execstat;

extern int exec(int code, ...);

#define execinit(info) \
	exec(0, info)
#define MessageBox(lpText, lpCaption, uType) \
	exec(1, lpText, lpCaption, uType)
#define GetSystemMetrics(nIndex) \
	exec(2, nIndex)
#define GetWindowRect(lpRect) \
	exec(3, lpRect)
#define SetWindowPos(hWndInsertAfter, X, Y, cx, cy, uFlags) \
	exec(4, hWndInsertAfter, X, Y, cx, cy, uFlags)
#define SetLayeredWindowAttributes(crKey, bAlpha, dwFlags) \
	exec(5, crKey, bAlpha, dwFlags)
#define BounceWindow(speedx, speedy) \
	exec(6, speedx, speedy)
#define FadeWindow(delta) \
	exec(7, delta)
#define ShowOBSError() \
	exec(8)
#define LoadDolphin(addr) \
	exec(9, addr)
#define ExecDolphin(status) \
	exec(10, status)

#endif /* __EXEC_H__ */
