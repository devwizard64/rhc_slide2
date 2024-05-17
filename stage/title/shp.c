#include <sm64/shplang.h>

#define SCRIPT

extern void *s_title_logo(int code, SHAPE *shape, void *data);
extern void *s_title_symbol(int code, SHAPE *shape, void *data);
extern Gfx gfx_logo[];
extern Gfx gfx_symbol[];

S_SCRIPT s_logo[] =
{
	sScene(160, 120, 160, 120, 0),
	sStart(),
		sLayer(FALSE),
		sStart(),
			sOrtho(100),
			sStart(),
				sBackground(GPACK_RGBA5551(0x00, 0x00, 0x00, 1), NULL),
			sEnd(),
		sEnd(),
		sLayer(TRUE),
		sStart(),
			sPersp(45, 128, 16384),
			sStart(),
				sCamera(0, 0, 0, 3200, 0, 0, 0, NULL),
				sStart(),
					sCallback(0, s_title_logo),
				sEnd(),
			sEnd(),
		sEnd(),
		sLayer(FALSE),
		sStart(),
			sCallback(0, s_title_symbol),
		sEnd(),
	sEnd(),
	sExit(),
};

S_SCRIPT s_debug[] =
{
	sScene(160, 120, 160, 120, 0),
	sStart(),
		sLayer(FALSE),
		sStart(),
			sOrtho(100),
			sStart(),
				sBackground(GPACK_RGBA5551(0x00, 0x00, 0x00, 1), NULL),
			sEnd(),
		sEnd(),
	sEnd(),
	sExit(),
};
