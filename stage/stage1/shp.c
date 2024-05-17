#include <sm64/shplang.h>

#define SCRIPT

#include "rainbowroad/shape.c"

extern void *extmessage_draw(int code, SHAPE *shape, void *data);

S_SCRIPT s_extmessage[] =
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
		sLayer(FALSE),
		sStart(),
			sCallback(0, extmessage_draw),
		sEnd(),
	sEnd(),
	sExit(),
};
