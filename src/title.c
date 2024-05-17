#include <sm64.h>

static const char *str_stage[] =
{
	"RAINBOW",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"ENDING",
	"",
	"EXT4 MINI SLID",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
};

long title_debug(UNUSED SHORT code, UNUSED long status)
{
	int flag = FALSE;
	if (cont1->down & A_BUTTON) stage_index +=  1, flag = TRUE;
	if (cont1->down & B_BUTTON) stage_index -=  1, flag = TRUE;
	if (cont1->down & U_JPAD)   stage_index -=  1, flag = TRUE;
	if (cont1->down & D_JPAD)   stage_index +=  1, flag = TRUE;
	if (cont1->down & L_JPAD)   stage_index -= 10, flag = TRUE;
	if (cont1->down & R_JPAD)   stage_index += 10, flag = TRUE;
	if (flag) Na_FixSePlay(NA_SE3_2B);
	if (stage_index > 38) stage_index =  1;
	if (stage_index <  1) stage_index = 38;
	file_index = 4;
	level_index = 6;
	dprintc(SCREEN_WD/2, 80, "SELECT STAGE");
	dprintc(SCREEN_WD/2, 30, "PRESS START BUTTON");
	dprintf(40, 60, "%2d", stage_index);
	dprint(80, 60, str_stage[stage_index-1]);
	if (cont1->down & START_BUTTON)
	{
		if (cont1->held == (Z_TRIG|START_BUTTON|L_CBUTTONS|R_CBUTTONS))
		{
			debug_stage = FALSE;
			return -1;
		}
		Na_FixSePlay(NA_SE7_1E);
		return stage_index;
	}
	return 0;
}

long title_logo(UNUSED SHORT code, UNUSED long status)
{
	Na_FixSePlay(NA_SE7_14);
	return debug_stage ? EXIT_DEBUG : STAGE_PSS;
}
