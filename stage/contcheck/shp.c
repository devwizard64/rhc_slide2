#include <sm64/shplang.h>

#define SCRIPT

extern void *contcheck_draw(int code, SHAPE *shape, void *data);

S_SCRIPT s_contcheck[] =
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
			sCallback(0, contcheck_draw),
		sEnd(),
	sEnd(),
	sExit(),
};
