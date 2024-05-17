#include <sm64.h>

extern s32 osCicScramble(OSMesgQueue *mq, void *buf);

#include "io/dolphin_pad.h"

extern PADStatus pad_status[MAXCONTROLLERS];

#include "PL.h"
#include "aes.h"
#include "exec.h"

typedef struct payload
{
	EXECINFO info;
	PL_Version version;
	unsigned char message[1];
}
PAYLOAD;

typedef struct header
{
	int bsd;
	int clock;
	long entry;
	int sdk;
	int checksum[2];
	long long _18;
	char title[20];
	char _34[7];
	char icode[4];
	char version;
}
HEADER;

typedef struct extwork
{
	u32 avatar[1024];
	char buffer[3072];
	HEADER header;
}
EXTWORK;

static PAYLOAD *const payload = (PAYLOAD *)0x80025C00;

static EXTWORK extwork;
extern AESWORK aeswork;

extern const char _execSegmentRomStart[];
extern const char _execSegmentRomEnd[];
extern char _execSegmentEnd[];

static void extdma(void *dram, long cart, size_t size)
{
	OSIoMesg mb;
	OSMesgQueue mq;
	OSMesg mbox[1];
	osCreateMesgQueue(&mq, mbox, 1);
	osInvalDCache(dram, size);
	osPiStartDma(&mb, OS_MESG_PRI_NORMAL, OS_READ, cart, dram, size, &mq);
	osRecvMesg(&mq, NULL, OS_MESG_BLOCK);
}

static void extslidec(char *dst, const char *src, const char *end)
{
	int bit = 0;
	int cnt = 1;
	do
	{
		if (cnt == 0)
		{
			bit = *src++ << 24;
			cnt = 8;
		}
		if (bit < 0)
		{
			int x = (unsigned char)src[0] << 8 | (unsigned char)src[1];
			int n = x >> 12;
			char *p = dst - ((x & 0xFFF)+1);
			src += 2;
			if (n == 0) n = 3+0xF + (unsigned char)*src++;
			else n += 2;
			for (; n > 0; n--) *dst++ = *p++;
		}
		else
		{
			*dst++ = *src++;
		}
		bit <<= 1;
		cnt--;
	}
	while (src < end);
}

static int extsum(char *data, size_t size)
{
	size_t i;
	int sum = 0;
	for (i = 0; i < size; i += 4) sum += *(int *)(data+i);
	return sum;
}

static void extxor(char *data, const char *key)
{
	int i;
	for (i = 0; i < 15; i++) data[i] ^= key[i];
}

static void extunscramble(char *data, size_t size)
{
	int i;
	char iv[15] = {0};
	for (i = size-15; i > -15; i -= 15)
	{
		char buf[15];
		char *p = data + i;
		memcpy(buf, p, 15);
		osCicScramble(&si_mq, p);
		extxor(p, iv);
		memcpy(iv, buf, 15);
	}
}

static void extunpack(char *dst, const char *src)
{
	int i;
	for (i = 0; i < 4096; i++)
	{
		if ((i & 3) < 3) *dst++ = src[i];
	}
}

static char *rstrip(char *str)
{
	int i;
	for (i = 19; i >= 0 && str[i] == ' '; i--) str[i] = '\0';
	return str;
}

#if 0
static const u32 extdata[] =
{
#include "ext/redire.h"
};
#define PL_GetAvatar _PL_GetAvatar
static int _PL_GetAvatar(
	UNUSED const char *username, u32 *avatar, UNUSED int siz, UNUSED int flag
)
{
	bcopy(extdata, avatar, sizeof(extdata));
	return PL_OK;
}
#endif

static int extload(void)
{
	PL_Version version;
	u32 *iv = (u32 *)aeswork.iv;
	char *addr = (char *)ADDRESS_EXEC;
	size_t size = _execSegmentRomEnd - _execSegmentRomStart;
	if (PL_GetMagic() != 'P') return -1;
	if (PL_GetCoreVersion(&version) != PL_OK) return -1;
	extdma(&extwork.header, 0, 64);
	if (PL_GetAvatar(
		rstrip(extwork.header.title), extwork.avatar, G_IM_SIZ_32b, TRUE
	) != PL_OK) return -1;
	extunpack(extwork.buffer, (char *)extwork.avatar);
	extunscramble(extwork.buffer, 3072);
	extdma(addr, (long)_execSegmentRomStart, size);
	bzero(addr+size, _execSegmentEnd-(addr+size));
	iv[0] = -extwork.header.checksum[1];
	iv[1] =  extwork.header.checksum[0];
	iv[2] =  extwork.header.checksum[1];
	iv[3] = ~extwork.header.checksum[0];
	osCicScramble(&si_mq, iv);
	aes_init();
	aes_set_key(&aeswork, extwork.buffer);
	aes_cbc_decrypt(&aeswork, addr, size);
	if (extsum(addr, size) != 0) return -1;
	extslidec((char *)payload, extwork.buffer+32, extwork.buffer+3072);
	if (!(
		version.major == payload->version.major &&
		version.minor == payload->version.minor &&
		version.patch == payload->version.patch
	)) return 1;
	return 0;
}

static char extstatus = -1;

extern const char _dolphinSegmentRomStart[];

int extinit(void)
{
	extstatus = extload();
	bzero(&extwork, sizeof(EXTWORK));
	if (extstatus)
	{
		((int *)ADDRESS_EXEC)[0] = 0x03E00008;
		((int *)ADDRESS_EXEC)[1] = 0x00000000;
	}
	else
	{
		unsigned char *str;
		for (str = payload->message; *str != CH_NUL; str++);
		((int (*)(void))(((long)str+1+3) & ~3))();
		execinit(&payload->info);
		LoadDolphin(_dolphinSegmentRomStart);
	}
	return extstatus;
}

static char extstate;
static char extphase;
static short exttimer;

void extexec(int state)
{
	if (extstatus) return;
	if (extstate == 0)
	{
		extstate = state;
		extphase = 0;
		exttimer = 0;
	}
}

int extproc(void)
{
	int result = FALSE;
	if (extstatus) return result;
	switch (extstate)
	{
	case 1:
		if (--exttimer < 0)
		{
			switch (++extphase)
			{
			case 1:
			case 3:
				Na_FixSePlay(0x0457C081);
				exttimer = 15;
				break;
			case 2:
				exttimer = 15 + (rand() & 15);
				break;
			case 4:
				extstate = 0;
				break;
			}
		}
		switch (extphase)
		{
		case 1:
			FadeWindow(-16);
			break;
		case 2:
			BounceWindow(93, 89);
			break;
		case 3:
			FadeWindow(16);
			break;
		}
		break;
	case 2:
		switch (exttimer++)
		{
		case 0:
		case 6:
		case 30*5+3:
			SetLayeredWindowAttributes(RGB(0x00, 0x00, 0x00), 0, LWA_COLORKEY);
			break;
		case 3:
		case 30*5+0:
		case 30*5+6:
			SetLayeredWindowAttributes(0, 0, 0);
			break;
		case 30*5+7:
			extstate = 0;
			break;
		}
		break;
	case 3:
		switch (exttimer++)
		{
		case 0:
			ShowOBSError();
			break;
		case 30*10:
			extstate = 0;
			break;
		}
		break;
	case 4:
		switch (exttimer++)
		{
		case 0:
			aud_fadeout(NA_TIME(30*3/2));
			scene_wipe(WIPE_FADE_OUT, 30, 0xFF, 0xFF, 0xFF);
			break;
		case 30:
			ExecDolphin(pad_status);
			result = TRUE;
			break;
		}
	}
	return result;
}

extern Gfx gfx_lgfont_start[];
extern Gfx gfx_lgfont_end[];

void *extmessage_draw(int code, UNUSED SHAPE *shape, UNUSED void *data)
{
	switch (code)
	{
	case SC_DRAW:
		gfx_screenproj();
		gSPDisplayList(glistp++, gfx_lgfont_start);
		gDPSetEnvColor(glistp++, 0xFF, 0xFF, 0xFF, 0xFF);
		print_lg(16, SCREEN_HT-16-16, payload->message);
		gSPDisplayList(glistp++, gfx_lgfont_end);
		break;
	}
	return NULL;
}

long extmessage_proc(SHORT code, UNUSED long status)
{
	int result = FALSE;
	if (extstatus) return result;
	switch (code)
	{
	case 0:
		if (payload->message[0] != CH_NUL) result = TRUE;
		break;
	case 1:
		if ((gfx_frame & 31) < 20) dprint(SCREEN_WD-20-12*7, 16, "PRESS A");
		if (contp->down & (A_BUTTON|START_BUTTON)) result = TRUE;
		break;
	}
	return result;
}
