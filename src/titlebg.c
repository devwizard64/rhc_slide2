#include <sm64.h>

extern Gfx gfx_wipe_start[];

extern Gfx gfx_logo[];
extern Gfx gfx_symbol[];
extern float logo_scale_a[];
extern float logo_scale_b[];

static short titlebg_frame;
static short titlebg_alpha;

void *s_title_logo(int code, SHAPE *shape, UNUSED void *data)
{
	S_CALLBACK *shp = (S_CALLBACK *)shape;
	Gfx *gfx = NULL;
	Gfx *g = NULL;
	Mtx *mtx;
	float *a = segment_to_virtual(logo_scale_a);
	float *b = segment_to_virtual(logo_scale_b);
	if (code != SC_DRAW)
	{
		titlebg_frame = 0;
	}
	else if (code == SC_DRAW)
	{
		float x, y, z;
		shape_set_layer(&shp->s, LAYER_OPA_SURF);
		mtx = gfx_alloc(sizeof(Mtx));
		g = gfx = gfx_alloc(sizeof(Gfx)*4);
		if (titlebg_frame >= 0 && titlebg_frame < 0+20)
		{
			x = a[3*(titlebg_frame-0)+0];
			y = a[3*(titlebg_frame-0)+1];
			z = a[3*(titlebg_frame-0)+2];
		}
		else if (titlebg_frame >= 0+20 && titlebg_frame < 75)
		{
			x = 1;
			y = 1;
			z = 1;
		}
		else if (titlebg_frame >= 75 && titlebg_frame < 75+16)
		{
			x = b[3*(titlebg_frame-75)+0];
			y = b[3*(titlebg_frame-75)+1];
			z = b[3*(titlebg_frame-75)+2];
		}
		else
		{
			x = 0;
			y = 0;
			z = 0;
		}
		guScale(mtx, x, y, z);
		gSPMatrix(g++, mtx, G_MTX_MODELVIEW|G_MTX_MUL|G_MTX_PUSH);
		gSPDisplayList(g++, gfx_logo);
		gSPPopMatrix(g++, G_MTX_MODELVIEW);
		gSPEndDisplayList(g);
		titlebg_frame++;
	}
	return gfx;
}

void *s_title_symbol(int code, SHAPE *shape, UNUSED void *data)
{
	S_CALLBACK *shp = (S_CALLBACK *)shape;
	Gfx *gfx = NULL;
	Gfx *g = NULL;
	if (code != SC_DRAW)
	{
		titlebg_alpha = 0;
	}
	else if (code == SC_DRAW)
	{
		g = gfx = gfx_alloc(sizeof(Gfx)*5);
		gSPDisplayList(g++, gfx_wipe_start);
		gDPSetEnvColor(g++, 0xFF, 0xFF, 0xFF, titlebg_alpha);
		switch (titlebg_alpha)
		{
		case 0xFF:
			shape_set_layer(&shp->s, LAYER_OPA_SURF);
			gDPSetRenderMode(g++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
			break;
		default:
			shape_set_layer(&shp->s, LAYER_XLU_SURF);
			gDPSetRenderMode(g++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
			break;
		}
		gSPDisplayList(g++, gfx_symbol);
		gSPEndDisplayList(g);
		if (titlebg_frame > 18)
		{
			titlebg_alpha += 26;
			if (titlebg_alpha > 0xFF) titlebg_alpha = 0xFF;
		}
	}
	return gfx;
}
