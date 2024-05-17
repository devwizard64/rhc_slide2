#include <sm64.h>

#define BGMCTL_GE_X     0
#define BGMCTL_GE_Y     1
#define BGMCTL_GE_Z     2
#define BGMCTL_LT_X     3
#define BGMCTL_LT_Y     4
#define BGMCTL_LT_Z     5
#define BGMCTL_SCENE    6
#define BGMCTL_AREA     7

#define BGMCTL(x)       (0x8000 >> BGMCTL_##x)

const char str_Na_game_803394F0[] = "AUTOSEQ ";
const char str_Na_game_803394FC[] = "%2x %2x <%5x : %5x / %5x>\n";
const char str_Na_game_80339518[] = "AUTOBNK ";
const char str_Na_game_80339524[] = "%2x %3x <%5x : %5x / %5x>\n";
const char str_Na_game_80339540[] = "STAYSEQ ";
const char str_Na_game_8033954C[] = "[%2x] <%5x / %5x>\n";
const char str_Na_game_80339560[] = "%2x ";
const char str_Na_game_80339568[] = "\n";
const char str_Na_game_8033956C[] = "STAYBNK ";
const char str_Na_game_80339578[] = "[%2x] <%5x / %5x>\n";
const char str_Na_game_8033958C[] = "%2x ";
const char str_Na_game_80339594[] = "\n\n";
const char str_Na_game_80339598[] = "    0123456789ABCDEF0123456789ABCDEF01234567\n";
const char str_Na_game_803395C8[] = "--------------------------------------------\n";
const char str_Na_game_803395F8[] = "SEQ ";
const char str_Na_game_80339600[] = "%1x";
const char str_Na_game_80339604[] = "\n";
const char str_Na_game_80339608[] = "BNK ";
const char str_Na_game_80339610[] = "%1x";
const char str_Na_game_80339614[] = "\n";
const char str_Na_game_80339618[] = "FIXHEAP ";
const char str_Na_game_80339624[] = "%4x / %4x\n";
const char str_Na_game_80339630[] = "DRVHEAP ";
const char str_Na_game_8033963C[] = "%5x / %5x\n";
const char str_Na_game_80339648[] = "DMACACHE  %4d Blocks\n";
const char str_Na_game_80339660[] = "CHANNELS  %2d / MAX %3d \n";
const char str_Na_game_8033967C[] = "TEMPOMAX  %d\n";
const char str_Na_game_8033968C[] = "TEMPO G0  %d\n";
const char str_Na_game_8033969C[] = "TEMPO G1  %d\n";
const char str_Na_game_803396AC[] = "TEMPO G2  %d\n";
const char str_Na_game_803396BC[] = "DEBUGFLAG  %8x\n";
const char str_Na_game_803396CC[] = "COUNT %8d\n";
const char str_Na_game_803396D8[] = "DAC:Lost 1 Frame.\n";
const char str_Na_game_803396EC[] = "DMA: Request queue over.( %d )\n";
const double Na_game_80339710 = 127;
const double Na_game_80339718 = 127;
const float Na_game_80339720 = 22000;
const float Na_game_80339724 = 44000;
const float Na_game_80339728 = 44000;
const float Na_game_8033972C = 22000;
const float Na_game_80339730 = 0.08F;
const float Na_game_80339734 = 22000;
const float Na_game_80339738 = 0.9F;

extern void L8031FF5C(void);
extern void L803200B0(void);
extern void L803200D4(void);
extern void L80320138(void);

void (*const Na_game_8033973C[])(void) =
{
	L803200D4,
	L8031FF5C,
	L803200D4,
	L80320138,
	L80320138,
	L80320138,
	L80320138,
	L803200B0,
	L80320138,
	L80320138,
};

extern void L8032026C(void);
extern void L803203BC(void);
extern void L803203DC(void);
extern void L80320440(void);

void (*const Na_game_80339764[])(void) =
{
	L803203DC,
	L8032026C,
	L803203DC,
	L80320440,
	L80320440,
	L80320440,
	L80320440,
	L803203BC,
	L80320440,
	L80320440,
};

extern void L80320A4C(void);
extern void L80320A8C(void);
extern void L80320ACC(void);
extern void L80320B0C(void);
extern void L80320B4C(void);
extern void L80320B8C(void);
extern void L80320BCC(void);
extern void L80320BF4(void);

void (*const Na_game_8033978C[])(void) =
{
	L80320A4C,
	L80320A8C,
	L80320ACC,
	L80320B0C,
	L80320B4C,
	L80320B8C,
	L80320BCC,
	L80320BF4,
};

BALIGN char _Na_game_bss[0x3710];

DALIGN s32 Na_game_80332E50 = 0;
DALIGN s32 Na_game_80332E54 = 0;

u8 Na_MsgSeTable[] =
{
	-1,  6,  6,  6,  6,  3,  3,  3, -1,  3,
	-1, -1, -1, -1, -1, -1, -1,  4, -1, -1,
	-1,  2,  2,  2,  2,  2,  2,  2,  2,  2,
	-1, -1, -1, -1, -1, -1, -1,  1, -1, -1,
	-1,  3, -1, -1, -1, -1, -1,  6, -1, -1,
	-1, -1, -1, -1, -1,  1,  1,  1,  1,  1,
	-1, -1, -1, -1, -1, -1, -1,  7, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1,  0,
	 0, -1, -1, -1, -1,  5, -1, -1, -1, -1,
	 7, -1,  7,  7, -1, -1, -1, -1,  5,  5,
	 0,  0, -1, -1, -1,  6,  6,  5,  5, -1,
	-1, -1, -1, -1,  8,  8,  4,  8,  8, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,  4, -1,
	-1, -1,  1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	 9,  9,  9, -1, -1, -1, -1, -1, -1, -1,
	-1, 10, -1, -1, -1, -1, -1, -1,  9, -1,
	-1, -1, -1, -1,
};

Na_Se Na_MsgSeData[15] =
{
	NA_SE5_21,
	NA_SE5_2D,
	NA_SE5_5F,
	NA_SE5_3D,
	NA_SE5_41,
	NA_SE5_48,
	NA_SE5_58,
	NA_SE5_38,
	NA_SE9_69,
	NA_SE5_6F,
	NA_SE3_70,
};

DALIGN u8 Na_game_80332F40 = 0;
DALIGN u8 Na_game_80332F44 = 0;

static s16 Na_BgmCtlNULL[] =
{
	NA_BGM_NULL,
	(s16)(0),
};

DALIGN u8 Na_game_80332FBC = -1;
DALIGN u8 Na_game_80332FC0 = -1;

s16 *Na_BgmCtlTable[] =
{
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
	Na_BgmCtlNULL,
};

Na_BgmCtl Na_BgmCtlData[] =
{
	{(s16)0xFFFF, 0x7F, 100, (s16)0x0000, 0x00, 100},
};

u8 Na_game_803330C0[][3] =
{
	{0x00, 0x00, 0x00},
	{0x28, 0x28, 0x28},
	{0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00},
	{0x28, 0x28, 0x28},
	{0x10, 0x38, 0x38},
	{0x20, 0x20, 0x30},
	{0x28, 0x28, 0x28},
	{0x08, 0x30, 0x30},
	{0x08, 0x08, 0x08},
	{0x10, 0x28, 0x28},
	{0x10, 0x18, 0x18},
	{0x10, 0x18, 0x18},
	{0x0C, 0x0C, 0x20},
	{0x18, 0x18, 0x18},
	{0x20, 0x20, 0x20},
	{0x08, 0x08, 0x08},
	{0x28, 0x28, 0x28},
	{0x28, 0x28, 0x28},
	{0x28, 0x28, 0x28},
	{0x10, 0x10, 0x10},
	{0x28, 0x28, 0x28},
	{0x08, 0x30, 0x30},
	{0x10, 0x20, 0x20},
	{0x08, 0x08, 0x08},
	{0x00, 0x00, 0x00},
	{0x08, 0x08, 0x08},
	{0x28, 0x28, 0x28},
	{0x28, 0x28, 0x28},
	{0x20, 0x20, 0x20},
	{0x40, 0x40, 0x40},
	{0x28, 0x28, 0x28},
	{0x70, 0x00, 0x00},
	{0x40, 0x40, 0x40},
	{0x40, 0x40, 0x40},
	{0x00, 0x00, 0x00},
	{0x08, 0x08, 0x08},
	{0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00},
};

u16 Na_game_80333138[] =
{
	20000,
	20000,
	20000,
	20000,
	28000,
	17000,
	20000,
	16000,
	15000,
	15000,
	14000,
	17000,
	20000,
	20000,
	18000,
	20000,
	25000,
	16000,
	30000,
	16000,
	20000,
	16000,
	22000,
	17000,
	13000,
	20000,
	20000,
	20000,
	18000,
	20000,
	60000,
	20000,
	20000,
	60000,
	60000,
	20000,
	15000,
	20000,
	20000,
};

u8 Na_BgmVolTable[] =
{
	127,
	80,
	80,
	80,
	80,
};

DALIGN u8 Na_game_803331AC = -1;
DALIGN u8 Na_game_803331B0 = 0;
u8 Na_game_803331B4[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
u8 Na_game_803331C0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
u8 Na_game_803331CC[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
u8 Na_game_803331D8[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
u8 Na_game_803331E4[] = {0x70, 0x30, 0x40, 0x80, 0x20, 0x80, 0x20, 0x40, 0x80, 0x80};
VECF Na_0 = {0, 0, 0};
VECF Na_1 = {1, 1, 1};
u8 Na_PortStatus[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
DALIGN u8 Na_game_80333214 = 0;
DALIGN u8 Na_game_80333218 = 0;
DALIGN u8 Na_game_8033321C = 0;
DALIGN u16 Na_game_80333220 = 0;
DALIGN u8 Na_game_80333224 = 0;
DALIGN u16 Na_game_80333228 = 0;
DALIGN u8 Na_game_8033322C = 0;
DALIGN u8 Na_game_80333230 = 0;
DALIGN u8 Na_game_80333234 = 0;
DALIGN u8 Na_game_80333238 = 0;
DALIGN u8 Na_game_8033323C = 0;

Na_Se Na_game_80333240[] =
{
	0x10000000, 0x10000000, 0x10000000, 0x10000000,
	0x10000000, 0x10000000, 0x10000000, 0x10000000,
	0x10000000, 0x10000000, 0x10000000, 0x10000000,
	0x10000000, 0x10000000, 0x10000000, 0x10000000,
};

u8 Na_game_80333280[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
u8 Na_game_80333290[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
