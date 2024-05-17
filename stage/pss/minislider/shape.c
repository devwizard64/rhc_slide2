#ifndef SCRIPT

static Lights1 light_minislider[] =
{
	gdSPDefLight(0.25, 0x8C, 0x8C, 0x8C),
	gdSPDefLight(0.25, 0xFF, 0xFF, 0xFF),
};

#include "0.h"

static Gfx gfx_minislider_0_i21[] =
{
	gsDPLoadImageBlock(txt_i_21, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32),
	gsSPSetLights1N(light_minislider[0]),
#include "0.i21_shade.h"
	gsSPSetLights1N(light_minislider[1]),
#include "0.i21_light.h"
	gsSPEndDisplayList(),
};

static Gfx gfx_minislider_0_0[] =
{
	gsDPLoadImageBlock(txt_pss_0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32),
#include "0.0_light.h"
	gsSPEndDisplayList(),
};

static Gfx gfx_minislider_0_i0[] =
{
	gsDPLoadImageBlock(txt_i_0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32),
#include "0.i0_light.h"
	gsSPEndDisplayList(),
};

static Gfx gfx_minislider_0_i10[] =
{
	gsDPLoadImageBlock(txt_i_10, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 64),
#include "0.i10_light.h"
	gsSPEndDisplayList(),
};

static Gfx gfx_minislider_0_i2[] =
{
	gsDPLoadImageBlock(txt_i_2, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 64),
#include "0.i2_light.h"
	gsSPEndDisplayList(),
};

Gfx gfx_minislider_0[] =
{
	gsDPPipeSync(),
	gsDPSetCycleType(G_CYC_2CYCLE),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
	gsDPSetDepthSource(G_ZS_PIXEL),
	gsDPSetFogColor(0x00, 0x00, 0x00, 0xFF),
	gsSPFogPosition(980, 1000),
	gsSPSetGeometryMode(G_FOG),
	gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_PASS2),
	gsDPSetLoadTile(G_IM_FMT_RGBA, G_IM_SIZ_16b),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_ON),
	gsDPSetImageBlock(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_WRAP, G_TX_WRAP, 5, 5, 0, 0),
	gsSPDisplayList(gfx_minislider_0_i21),
	gsSPDisplayList(gfx_minislider_0_0),
	gsSPDisplayList(gfx_minislider_0_i0),
	gsDPSetImageBlock(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 64, 0, G_TX_WRAP, G_TX_WRAP, 5, 6, 0, 0),
	gsSPDisplayList(gfx_minislider_0_i10),
	gsDPSetImageBlock(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 64, 0, G_TX_WRAP, G_TX_CLAMP, 5, 6, 0, 0),
	gsSPDisplayList(gfx_minislider_0_i2),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_OFF),
	gsDPPipeSync(),
	gsDPSetCycleType(G_CYC_1CYCLE),
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_NOOP2),
	gsSPClearGeometryMode(G_FOG),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsSPEndDisplayList(),
};

#include "1.h"

static Gfx gfx_minislider_1_i21[] =
{
	gsDPLoadImageBlock(txt_i_21, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32),
#include "1.i21.h"
	gsSPEndDisplayList(),
};

static Gfx gfx_minislider_1_i0[] =
{
	gsDPLoadImageBlock(txt_i_0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32),
#include "1.i0.h"
	gsSPEndDisplayList(),
};

static Gfx gfx_minislider_1_i12[] =
{
	gsDPLoadImageBlock(txt_i_12, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32),
#include "1.i12.h"
	gsSPEndDisplayList(),
};

Gfx gfx_minislider_1[] =
{
	gsDPPipeSync(),
	gsDPSetCycleType(G_CYC_2CYCLE),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
	gsDPSetDepthSource(G_ZS_PIXEL),
	gsDPSetFogColor(0x00, 0x00, 0x00, 0xFF),
	gsSPFogPosition(980, 1000),
	gsSPSetGeometryMode(G_FOG),
	gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_PASS2),
	gsSPClearGeometryMode(G_LIGHTING),
	gsDPSetLoadTile(G_IM_FMT_RGBA, G_IM_SIZ_16b),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_ON),
	gsDPSetImageBlock(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_WRAP, G_TX_WRAP, 5, 5, 0, 0),
	gsSPDisplayList(gfx_minislider_1_i21),
	gsSPDisplayList(gfx_minislider_1_i0),
	gsSPDisplayList(gfx_minislider_1_i12),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_OFF),
	gsDPPipeSync(),
	gsDPSetCycleType(G_CYC_1CYCLE),
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_NOOP2),
	gsSPClearGeometryMode(G_FOG),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};

#include "2.h"

static Gfx gfx_minislider_2_i13[] =
{
	gsDPLoadImageBlock(txt_i_13, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32),
#include "2.i13.h"
	gsSPEndDisplayList(),
};

Gfx gfx_minislider_2[] =
{
	gsDPPipeSync(),
	gsDPSetCycleType(G_CYC_2CYCLE),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
	gsDPSetDepthSource(G_ZS_PIXEL),
	gsDPSetFogColor(0x00, 0x00, 0x00, 0xFF),
	gsSPFogPosition(980, 1000),
	gsSPSetGeometryMode(G_FOG),
	gsDPSetCombineMode(G_CC_DECALRGB, G_CC_PASS2),
	gsSPClearGeometryMode(G_CULL_BACK|G_LIGHTING),
	gsDPSetLoadTile(G_IM_FMT_RGBA, G_IM_SIZ_16b),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_ON),
	gsDPSetImageBlock(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_WRAP, G_TX_WRAP, 5, 5, 0, 0),
	gsSPDisplayList(gfx_minislider_2_i13),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_OFF),
	gsDPPipeSync(),
	gsDPSetCycleType(G_CYC_1CYCLE),
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_NOOP2),
	gsSPClearGeometryMode(G_FOG),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsSPSetGeometryMode(G_CULL_BACK|G_LIGHTING),
	gsSPEndDisplayList(),
};

#include "3.h"

static Gfx gfx_minislider_3_i13[] =
{
	gsDPLoadImageBlock(txt_i_13, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32),
#include "3.i12.h"
	gsSPEndDisplayList(),
};

Gfx gfx_minislider_3[] =
{
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_DECALRGB, G_CC_DECALRGB),
	gsSPClearGeometryMode(G_LIGHTING),
	gsDPSetLoadTile(G_IM_FMT_RGBA, G_IM_SIZ_16b),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_ON),
	gsDPSetImageBlock(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_WRAP, G_TX_WRAP, 5, 5, 0, 0),
	gsSPDisplayList(gfx_minislider_3_i13),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_OFF),
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};

#include "4.h"

static Gfx gfx_minislider_4_1[] =
{
	gsDPLoadImageBlock(txt_pss_1, G_IM_FMT_IA, G_IM_SIZ_16b, 32, 32),
#include "4.1.h"
	gsSPEndDisplayList(),
};

Gfx gfx_minislider_4[] =
{
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBA, G_CC_MODULATERGBA),
	gsSPClearGeometryMode(G_LIGHTING),
	gsDPSetLoadTile(G_IM_FMT_IA, G_IM_SIZ_16b),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_ON),
	gsDPSetImageBlock(G_IM_FMT_IA, G_IM_SIZ_16b, 32, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 5, 5, 0, 0),
	gsSPDisplayList(gfx_minislider_4_1),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_OFF),
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};

#if 0
#include "5.h"

static Gfx gfx_minislider_5_i12[] =
{
	gsDPLoadImageBlock(txt_i_12, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32),
#include "5.i12.h"
	gsSPEndDisplayList(),
};

static Gfx gfx_minislider_5_0[] =
{
	gsDPLoadImageBlock(txt_pss_0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32),
#include "5.0.h"
	gsSPEndDisplayList(),
};

static Gfx gfx_minislider_5_i10[] =
{
	gsDPLoadImageBlock(txt_i_10, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 64),
#include "5.i10.h"
	gsSPEndDisplayList(),
};

Gfx gfx_minislider_5[] =
{
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_MODULATERGB),
	gsSPClearGeometryMode(G_LIGHTING),
	gsDPSetLoadTile(G_IM_FMT_RGBA, G_IM_SIZ_16b),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_ON),
	gsDPSetImageBlock(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_WRAP, G_TX_WRAP, 5, 5, 0, 0),
	gsSPDisplayList(gfx_minislider_5_i12),
	gsSPDisplayList(gfx_minislider_5_0),
	gsDPSetImageBlock(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 64, 0, G_TX_WRAP, G_TX_WRAP, 5, 6, 0, 0),
	gsSPDisplayList(gfx_minislider_5_i10),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_OFF),
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};
#endif

static Lights1 light_minislider_6[] =
{
	gdSPDefLight(0.25, 0xFF, 0xFF, 0xFF),
};

#include "6.h"

static Gfx gfx_minislider_6_2[] =
{
	gsDPLoadImageBlock(txt_pss_2, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32),
	gsSPSetLights1N(light_minislider_6[0]),
#include "6.2.h"
	gsSPEndDisplayList(),
};

Gfx gfx_minislider_6[] =
{
	gsDPPipeSync(),
	gsDPSetCycleType(G_CYC_2CYCLE),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_DECAL2),
	gsDPSetDepthSource(G_ZS_PIXEL),
	gsDPSetFogColor(0x00, 0x00, 0x00, 0xFF),
	gsSPFogPosition(980, 1000),
	gsSPSetGeometryMode(G_FOG),
	gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_PASS2),
	gsDPSetLoadTile(G_IM_FMT_RGBA, G_IM_SIZ_16b),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_ON),
	gsDPSetImageBlock(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_WRAP, G_TX_WRAP, 5, 5, 0, 0),
	gsSPDisplayList(gfx_minislider_6_2),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_OFF),
	gsDPPipeSync(),
	gsDPSetCycleType(G_CYC_1CYCLE),
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_DECAL, G_RM_NOOP2),
	gsSPClearGeometryMode(G_FOG),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsSPEndDisplayList(),
};

#else /* SCRIPT */

extern Gfx gfx_minislider_0[];
extern Gfx gfx_minislider_1[];
extern Gfx gfx_minislider_2[];
extern Gfx gfx_minislider_3[];
extern Gfx gfx_minislider_4[];
extern Gfx gfx_minislider_5[];
extern Gfx gfx_minislider_6[];

S_SCRIPT s_minislider[] =
{
	sScene(160, 120, 160, 120, 10),
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
			sPerspective(45, 100, 12800, s_stage_perspective),
			sStart(),
				sCamera(9, 0, 2000, 6000, 0, 0, 0, s_stage_camera),
				sStart(),
					sGfx(LAYER_OPA_SURF, gfx_minislider_0),
					sGfx(LAYER_OPA_SURF, gfx_minislider_1),
					sGfx(LAYER_OPA_SURF, gfx_minislider_2),
					sGfx(LAYER_OPA_SURF, gfx_minislider_3),
					sGfx(LAYER_XLU_SURF, gfx_minislider_4),
#if 0
					sGfx(LAYER_OPA_SURF, gfx_minislider_5),
#endif
					sGfx(LAYER_OPA_DECAL, gfx_minislider_6),
					sObject(),
				sEnd(),
			sEnd(),
		sEnd(),
	sEnd(),
	sExit(),
};

#endif /* SCRIPT */
