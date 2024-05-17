#include <sm64.h>

#include "logo.h"

static u16 txt_logo_wood[] =
{
#include "wood.rgba16.h"
};

static u16 txt_logo_marble[] =
{
#include "marble.rgba16.h"
};

static Gfx gfx_logo_marble[] =
{
	gsDPLoadImageBlock(txt_logo_marble, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32),
#include "logo.marble.h"
	gsSPEndDisplayList(),
};

static Gfx gfx_logo_wood[] =
{
	gsDPLoadImageBlock(txt_logo_wood, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32),
#include "logo.wood.h"
	gsSPEndDisplayList(),
};

static Gfx gfx_logo_shade[] =
{
#include "logo.shade.h"
	gsSPEndDisplayList(),
};

Gfx gfx_logo[] =
{
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_MODULATERGB),
	gsSPClearGeometryMode(G_LIGHTING),
	gsDPSetLoadTile(G_IM_FMT_RGBA, G_IM_SIZ_16b),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_ON),
	gsDPSetImageBlock(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_WRAP, G_TX_WRAP, 5, 5, 0, 0),
	gsSPDisplayList(gfx_logo_marble),
	gsSPDisplayList(gfx_logo_wood),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_OFF),
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsSPDisplayList(gfx_logo_shade),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};

static Vtx vtx_logo_symbol_subtitle[] =
{
	{{{    80,     42,     -1}, 0, {   -16,   1008}, { 255,  255,  255,  255}}},
	{{{   240,     42,     -1}, 0, {  8176,   1008}, { 255,  255,  255,  255}}},
	{{{   240,     58,     -1}, 0, {  8176,    -16}, { 255,  255,  255,  255}}},
	{{{    80,     58,     -1}, 0, {   -16,    -16}, { 255,  255,  255,  255}}},
};

static Vtx vtx_logo_symbol_trademark[] =
{
	{{{   268,    180,     -1}, 0, {     0,    512}, { 255,  255,  255,  255}}},
	{{{   284,    180,     -1}, 0, {   544,    512}, { 255,  255,  255,  255}}},
	{{{   284,    196,     -1}, 0, {   544,      0}, { 255,  255,  255,  255}}},
	{{{   268,    196,     -1}, 0, {     0,      0}, { 255,  255,  255,  255}}},
};

static u8 txt_logo_subtitle[] =
{
#include "subtitle.i4.h"
};

static u16 txt_logo_trademark[] =
{
#include "trademark.rgba16.h"
};

Gfx gfx_symbol[] =
{
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_DECALRGB_ENV, G_CC_DECALRGB_ENV),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_ON),
	gsDPLoadTextureBlock_4b(txt_logo_subtitle, G_IM_FMT_I, 256, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 8, 5, 0, 0),
	gsSPVertex(&vtx_logo_symbol_subtitle[0], 4, 0),
	gsSP2Triangles( 0,  1,  2, 0,  0,  2,  3, 0),
	gsDPLoadTextureBlock(txt_logo_trademark, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_CLAMP, G_TX_CLAMP, 4, 4, 0, 0),
	gsSPVertex(&vtx_logo_symbol_trademark[0], 4, 0),
	gsSP2Triangles( 0,  1,  2, 0,  0,  2,  3, 0),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_OFF),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsDPSetEnvColor(0xFF, 0xFF, 0xFF, 0xFF),
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
	gsSPEndDisplayList(),
};

float logo_scale_a[] =
{
	0.0160, 0.0520, 0.0025,
	0.1483, 0.1892, 0.0352,
	0.4716, 0.5253, 0.1166,
	0.8758, 0.9470, 0.2221,
	1.2505, 1.3413, 0.3270,
	1.4854, 1.5949, 0.4065,
	1.2305, 1.5637, 0.4643,
	0.9139, 1.3513, 0.5202,
	1.0229, 1.2161, 0.5744,
	1.1223, 1.0972, 0.6270,
	1.0283, 0.9556, 0.6781,
	0.9348, 1.0494, 0.7277,
	0.9942, 1.0052, 0.7759,
	1.0702, 0.9615, 0.8229,
	0.9956, 0.9950, 0.8687,
	0.9916, 1.0057, 0.9135,
	1.0165, 0.9852, 0.9572,
	0.9852, 1.0071, 1.0000,
	0.9999, 0.9998, 1.0106,
	1.0000, 1.0000, 1.0000,
};

float logo_scale_b[] =
{
	1.0000, 1.0000, 1.0000,
	0.9873, 0.9873, 0.9873,
	0.9514, 0.9514, 0.9514,
	0.8960, 0.8960, 0.8960,
	0.8246, 0.8246, 0.8246,
	0.7407, 0.7407, 0.7407,
	0.6480, 0.6480, 0.6480,
	0.5499, 0.5499, 0.5499,
	0.4501, 0.4501, 0.4501,
	0.3520, 0.3520, 0.3520,
	0.2593, 0.2593, 0.2593,
	0.1754, 0.1754, 0.1754,
	0.1040, 0.1040, 0.1040,
	0.0486, 0.0486, 0.0486,
	0.0128, 0.0128, 0.0128,
	0.0000, 0.0000, 0.0000,
};
