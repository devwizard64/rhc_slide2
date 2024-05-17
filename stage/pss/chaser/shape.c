#ifndef SCRIPT

static Vtx vtx_chaser[] =
{
	{{{  -100,     32,      0}, 0, {     0,    992}, {0xFF, 0xFF, 0x00, 0xFF}}},
	{{{   100,     32,      0}, 0, {  2016,    992}, {0xFF, 0xFF, 0x00, 0xFF}}},
	{{{   100,     96,      0}, 0, {  2016,      0}, {0xFF, 0xFF, 0x00, 0xFF}}},
	{{{  -100,     96,      0}, 0, {     0,      0}, {0xFF, 0xFF, 0x00, 0xFF}}},
	{{{  -100,    -32,      0}, 0, {     0,    992}, {0xFF, 0xFF, 0x00, 0xFF}}},
	{{{   100,    -32,      0}, 0, {  2016,    992}, {0xFF, 0xFF, 0x00, 0xFF}}},
	{{{   100,     32,      0}, 0, {  2016,      0}, {0xFF, 0xFF, 0x00, 0xFF}}},
	{{{  -100,     32,      0}, 0, {     0,      0}, {0xFF, 0xFF, 0x00, 0xFF}}},
	{{{  -100,    -96,      0}, 0, {     0,    992}, {0xFF, 0xFF, 0x00, 0xFF}}},
	{{{   100,    -96,      0}, 0, {  2016,    992}, {0xFF, 0xFF, 0x00, 0xFF}}},
	{{{   100,    -32,      0}, 0, {  2016,      0}, {0xFF, 0xFF, 0x00, 0xFF}}},
	{{{  -100,    -32,      0}, 0, {     0,      0}, {0xFF, 0xFF, 0x00, 0xFF}}},
};

Gfx gfx_chaser[] =
{
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
	gsSPClearGeometryMode(G_LIGHTING),
	gsDPSetLoadTile(G_IM_FMT_RGBA, G_IM_SIZ_16b),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_ON),
	gsDPSetImageBlock(G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 5, 0, 0),
	gsSPVertex(vtx_chaser, 12, 0),
	gsDPLoadImageBlock(0x01000000 + 2*64*31*0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
	gsSP2Triangles( 0,  1,  2, 0,  0,  2,  3, 0),
	gsDPLoadImageBlock(0x01000000 + 2*64*31*1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
	gsSP2Triangles( 4,  5,  6, 0,  4,  6,  7, 0),
	gsDPLoadImageBlock(0x01000000 + 2*64*31*2, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
	gsSP2Triangles( 8,  9, 10, 0,  8, 10, 11, 0),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_OFF),
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};

#else /* SCRIPT */

extern void *s_chaser_txt(int code, SHAPE *shape, void *data);
extern Gfx gfx_chaser[];

S_SCRIPT s_chaser[] =
{
	sEmpty(),
	sStart(),
		sCallback(0, s_chaser_txt),
		sGfx(LAYER_TEX_EDGE, gfx_chaser),
	sEnd(),
	sExit(),
};

#endif /* SCRIPT */
