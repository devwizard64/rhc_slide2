#include <sm64.h>

#include "io/dolphin_pad.h"

#include "sprite.h"

extern OSContPad cont_pad[];
extern PADStatus pad_status[];

extern u8 txt_contcheck_banner[];
extern u8 txt_contcheck_error[];
extern u16 txt_contcheck_pad[];
extern u16 txt_contcheck_stick[];
extern u16 txt_contcheck_substick[];
extern u16 txt_contcheck_triggerLeft[];
extern u16 txt_contcheck_triggerRight[];

#define PAD_X 60
#define PAD_Y 96

typedef struct pad_button
{
	short x;
	unsigned char y;
	char c;
}
PAD_BUTTON;

static const PAD_BUTTON pad_button[] =
{
#define PAD_BUTTON(x, y, c) {PAD_X/2+(x), 240-16-(PAD_Y/2+(y)), c}
	PAD_BUTTON( 66, 121, 'L'),
	PAD_BUTTON( 93, 121, 'R'),
	PAD_BUTTON( 80, 136, 'D'),
	PAD_BUTTON( 80, 108, 'U'),
	PAD_BUTTON(212,  10, 'Z'),
	PAD_BUTTON(214,  -8, 'R'),
	PAD_BUTTON( 32,  -8, 'L'),
	{0},
	PAD_BUTTON(205,  59, 'A'),
	PAD_BUTTON(177,  75, 'B'),
	PAD_BUTTON(237,  53, 'X'),
	PAD_BUTTON(199,  30, 'Y'),
	PAD_BUTTON(124,  62, 'S'),
	{0},
	{0},
	{0},
#undef PAD_BUTTON
};

static PADStatus *pad;

static void conttest_draw(void)
{
	int i;
	sprite_draw(
		txt_contcheck_triggerLeft, G_IM_FMT_RGBA, G_IM_SIZ_16b, TRUE, 75, 52,
		2*(PAD_X+42),
		2*(PAD_Y+10) + pad->triggerLeft/5,
		2*75, 2*52
	);
	sprite_draw(
		txt_contcheck_triggerRight, G_IM_FMT_RGBA, G_IM_SIZ_16b, TRUE, 75, 52,
		2*(PAD_X+403),
		2*(PAD_Y+10) + pad->triggerRight/5,
		2*75, 2*52
	);
	sprite_draw(
		txt_contcheck_pad, G_IM_FMT_RGBA, G_IM_SIZ_16b, TRUE, 520, 368,
		2*PAD_X, 2*PAD_Y, 2*520, 2*368
	);
	sprite_draw(
		txt_contcheck_stick, G_IM_FMT_RGBA, G_IM_SIZ_16b, TRUE, 76, 77,
		2*(PAD_X+ 96)-76 + pad->stickX*4/5,
		2*(PAD_Y+136)-77 - pad->stickY*4/5,
		2*76, 2*77
	);
	sprite_draw(
		txt_contcheck_substick, G_IM_FMT_RGBA, G_IM_SIZ_16b, TRUE, 50, 49,
		2*(PAD_X+347)-50 + pad->substickX*4/5,
		2*(PAD_Y+257)-49 - pad->substickY*4/5,
		2*50, 2*49
	);
	for (i = 0; i < 16; i++)
	{
		if (pad->button & (1 << i))
		{
			char buf[2];
			buf[0] = pad_button[i].c;
			buf[1] = '\0';
			dprint(pad_button[i].x, pad_button[i].y, buf);
		}
	}
}

void *contcheck_draw(int code, UNUSED SHAPE *shape, UNUSED void *data)
{
	switch (code)
	{
	case SC_DRAW:
		gDPPipeSync(glistp++);
		gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
		gSPSetOtherMode(
			glistp++, G_SETOTHERMODE_H, 0, 24,
			G_PM_1PRIMITIVE |
			G_CYC_1CYCLE |
			G_TP_NONE |
			G_TD_CLAMP |
			G_TL_TILE |
			G_TT_NONE |
			G_TF_BILERP |
			G_TC_FILT |
			G_CK_NONE |
			G_CD_MAGICSQ |
			G_AD_DISABLE |
			15
		);
		gSPSetOtherMode(
			glistp++, G_SETOTHERMODE_L, 0, 32,
			G_RM_XLU_SURF | G_RM_XLU_SURF2 |
			G_ZS_PIXEL |
			G_AC_NONE
		);
		if (pad)
		{
			sprite_draw(
				txt_contcheck_banner, G_IM_FMT_I, G_IM_SIZ_4b, TRUE, 578, 74,
				640-578, 2*16, 2*578, 2*74
			);
			conttest_draw();
		}
		else
		{
			sprite_draw(
				txt_contcheck_error, G_IM_FMT_I, G_IM_SIZ_4b, TRUE, 556, 24,
				640-556, 480-24, 2*556, 2*24
			);
		}
		break;
	}
	return NULL;
}

long contcheck_proc(UNUSED SHORT code, UNUSED long status)
{
	int result = 0;
	switch (code)
	{
	case 0:
		if (cont_bitpattern)
		{
			pad = &pad_status[cont1->pad-cont_pad];
		}
		else
		{
			pad = NULL;
			Na_FixSePlay(NA_SE7_0E);
		}
		break;
	case 1:
		if (pad)
		{
			if (
				!(~pad->button & (PAD_BUTTON_X|PAD_BUTTON_Y)) &&
				cont1->down & START_BUTTON
			)
			{
				result = 1;
			}
		}
		break;
	}
	return result;
}
