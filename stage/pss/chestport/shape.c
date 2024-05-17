#ifndef SCRIPT

#define G_CC_CHESTPORT 0, 0, 0, TEXEL0, SHADE, 0, ENVIRONMENT, 0

static Vtx vtx_chestport_base[] =
{
	{{{   -80,     25,     55}, 0, {     0,      0}, {0x00, 0x00, 0x00, 0x00}}},
	{{{    80,     25,     55}, 0, {     0,      0}, {0x00, 0x00, 0x00, 0x00}}},
	{{{    80,     25,    -55}, 0, {     0,      0}, {0x00, 0x00, 0x00, 0x00}}},
	{{{   -80,     25,    -55}, 0, {     0,      0}, {0x00, 0x00, 0x00, 0x00}}},
};

Gfx gfx_chestport_base[] =
{
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(&vtx_chestport_base[0], 4, 0),
	gsSP2Triangles( 0,  1,  2, 0,  0,  2,  3, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};

static Vtx vtx_chestport_cone[] =
{
	{{{     0,      0,    -50}, 0, {  2032,    240}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{     0,    256,   -100}, 0, {  2032,    -16}, {0xFF, 0xFF, 0xFF, 0x7F}}},
	{{{    71,    256,    -71}, 0, {  1776,    -16}, {0xFF, 0xFF, 0xFF, 0x7F}}},
	{{{    35,      0,    -35}, 0, {  1776,    240}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{   100,    256,      0}, 0, {  1520,    -16}, {0xFF, 0xFF, 0xFF, 0x7F}}},
	{{{    50,      0,      0}, 0, {  1520,    240}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{    71,    256,     71}, 0, {  1264,    -16}, {0xFF, 0xFF, 0xFF, 0x7F}}},
	{{{    35,      0,     35}, 0, {  1264,    240}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{     0,    256,    100}, 0, {  1008,    -16}, {0xFF, 0xFF, 0xFF, 0x7F}}},
	{{{     0,      0,     50}, 0, {  1008,    240}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{   -71,    256,     71}, 0, {   752,    -16}, {0xFF, 0xFF, 0xFF, 0x7F}}},
	{{{   -35,      0,     35}, 0, {   752,    240}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{  -100,    256,      0}, 0, {   496,    -16}, {0xFF, 0xFF, 0xFF, 0x7F}}},
	{{{   -50,      0,      0}, 0, {   496,    240}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{   -71,    256,    -71}, 0, {   240,    -16}, {0xFF, 0xFF, 0xFF, 0x7F}}},
	{{{   -35,      0,    -35}, 0, {   240,    240}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{   -35,      0,    -35}, 0, {   240,    240}, {0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{   -71,    256,    -71}, 0, {   240,    -16}, {0xFF, 0xFF, 0xFF, 0x7F}}},
	{{{     0,    256,   -100}, 0, {   -16,    -16}, {0xFF, 0xFF, 0xFF, 0x7F}}},
	{{{     0,      0,    -50}, 0, {   -16,    240}, {0xFF, 0xFF, 0xFF, 0xFF}}},
};

Gfx gfx_chestport_cone[] =
{
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_CHESTPORT, G_CC_CHESTPORT),
	gsSPClearGeometryMode(G_LIGHTING),
	gsDPSetLoadTile(G_IM_FMT_RGBA, G_IM_SIZ_16b),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_ON),
	gsDPSetImageBlock(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 8, 0, G_TX_WRAP, G_TX_WRAP, 5, 3, 0, 0),
	gsDPLoadImageBlock(txt_pss_3, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 8),
	gsSPVertex(&vtx_chestport_cone[0], 16, 0),
	gsSP2Triangles( 0,  1,  2, 0,  0,  2,  3, 0),
	gsSP2Triangles( 3,  2,  4, 0,  3,  4,  5, 0),
	gsSP2Triangles( 5,  4,  6, 0,  5,  6,  7, 0),
	gsSP2Triangles( 7,  6,  8, 0,  7,  8,  9, 0),
	gsSP2Triangles( 9,  8, 10, 0,  9, 10, 11, 0),
	gsSP2Triangles(11, 10, 12, 0, 11, 12, 13, 0),
	gsSP2Triangles(13, 12, 14, 0, 13, 14, 15, 0),
	gsSPVertex(&vtx_chestport_cone[16], 4, 0),
	gsSP2Triangles( 0,  1,  2, 0,  0,  2,  3, 0),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_OFF),
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};

#else /* SCRIPT */

extern void *s_chestport_cone(int code, SHAPE *shape, void *data);
extern Gfx gfx_chestport_base[];
extern Gfx gfx_chestport_cone[];

S_SCRIPT s_chestport[] =
{
	sEmpty(),
	sStart(),
		sGfx(LAYER_OPA_SURF, gfx_chestport_base),
		sCallback(0, s_objlib_8029D924),
		sCallback(0, s_chestport_cone),
		sCoord(0, 50, 0, 0, 0, 0),
		sStart(),
			sGfxScale(LAYER_XLU_SURF, gfx_chestport_cone, 0.8),
		sEnd(),
		sCoord(0, 30, 0, 0, 0, 0),
		sStart(),
			sGfxScale(LAYER_XLU_SURF, gfx_chestport_cone, 0.9),
		sEnd(),
	sEnd(),
	sExit(),
};

#endif /* SCRIPT */
