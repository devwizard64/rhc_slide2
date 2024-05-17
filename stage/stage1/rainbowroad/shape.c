#ifndef SCRIPT

#include "banner.h"
#include "character.h"

Gfx gfx_rainbowroad_opa_surf[] =
{
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_DECALRGB, G_CC_DECALRGB),
	gsSPClearGeometryMode(G_CULL_BACK|G_LIGHTING),
	gsDPSetLoadTile(G_IM_FMT_RGBA, G_IM_SIZ_16b),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_ON),
	gsDPSetImageBlock(G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 5, 0, 0),
	gsDPLoadImageBlock(txt_banner_ah, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "banner.banner_ah.h"
	gsDPLoadImageBlock(txt_banner_al, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "banner.banner_al.h"
	gsDPLoadImageBlock(txt_banner_bh, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "banner.banner_bh.h"
	gsDPLoadImageBlock(txt_banner_bl, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "banner.banner_bl.h"
	gsDPLoadImageBlock(txt_banner_ch, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "banner.banner_ch.h"
	gsDPLoadImageBlock(txt_banner_cl, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "banner.banner_cl.h"
	gsDPLoadImageBlock(txt_banner_dh, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "banner.banner_dh.h"
	gsDPLoadImageBlock(txt_banner_dl, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "banner.banner_dl.h"
	gsDPLoadImageBlock(txt_ch_donkey_h, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_donkey_h.h"
	gsDPLoadImageBlock(txt_ch_donkey_l, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_donkey_l.h"
	gsDPLoadImageBlock(txt_ch_kinoko_h, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_kinoko_h.h"
	gsDPLoadImageBlock(txt_ch_kinoko_l, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_kinoko_l.h"
	gsDPLoadImageBlock(txt_ch_kinopio_h, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_kinopio_h.h"
	gsDPLoadImageBlock(txt_ch_kinopio_l, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_kinopio_l.h"
	gsDPLoadImageBlock(txt_ch_kuppa_h, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_kuppa_h.h"
	gsDPLoadImageBlock(txt_ch_kuppa_l, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_kuppa_l.h"
	gsDPLoadImageBlock(txt_ch_luizi_h, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_luizi_h.h"
	gsDPLoadImageBlock(txt_ch_luizi_l, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_luizi_l.h"
	gsDPLoadImageBlock(txt_ch_mario_h, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_mario_h.h"
	gsDPLoadImageBlock(txt_ch_mario_l, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_mario_l.h"
	gsDPLoadImageBlock(txt_ch_peach_h, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_peach_h.h"
	gsDPLoadImageBlock(txt_ch_peach_l, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_peach_l.h"
	gsDPLoadImageBlock(txt_ch_teresa_h, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_teresa_h.h"
	gsDPLoadImageBlock(txt_ch_teresa_l, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_teresa_l.h"
	gsDPLoadImageBlock(txt_ch_wario_h, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_wario_h.h"
	gsDPLoadImageBlock(txt_ch_wario_l, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_wario_l.h"
	gsDPLoadImageBlock(txt_ch_yossy_h, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_yossy_h.h"
	gsDPLoadImageBlock(txt_ch_yossy_l, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "character.ch_yossy_l.h"
	gsDPSetImageBlock(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_CLAMP, G_TX_WRAP, 5, 5, 0, 0),
	gsDPLoadImageBlock(txt_ba_pole, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32),
#include "banner.ba_pole.h"
	gsSPSetGeometryMode(G_CULL_BACK|G_LIGHTING),
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsSPEndDisplayList(),
};

Gfx gfx_rainbowroad_tex_edge[] =
{
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
	gsSPClearGeometryMode(G_CULL_BACK|G_LIGHTING),
	gsDPSetLoadTile(G_IM_FMT_RGBA, G_IM_SIZ_16b),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_ON),
	gsDPSetImageBlock(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_WRAP, G_TX_WRAP, 5, 5, 0, 0),
	gsDPLoadImageBlock(txt_ba_cable, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32),
#include "banner.ba_cable.h"
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_OFF),
	gsSPSetGeometryMode(G_CULL_BACK|G_LIGHTING),
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsSPEndDisplayList(),
};

#include "track.h"

#define G_CC_TR_HOSI 0, 0, 0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0

Gfx gfx_rainbowroad_track[] =
{
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_DECALRGB_ENV, G_CC_DECALRGB_ENV),
	gsDPSetEnvColor(0xFF, 0xFF, 0xFF, 0x7F),
	gsSPClearGeometryMode(G_CULL_BACK|G_LIGHTING),
	gsDPSetLoadTile(G_IM_FMT_RGBA, G_IM_SIZ_16b),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_ON),
	gsDPSetImageBlock(G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_WRAP, G_TX_WRAP, 6, 5, 0, 0),
	gsDPLoadImageBlock(txt_tr_rainbow, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32),
#include "track.tr_rainbow.h"
	gsDPSetImageBlock(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_WRAP, G_TX_WRAP, 5, 5, 0, 0),
	gsDPLoadImageBlock(txt_tr_checker, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32),
#include "track.tr_checker.h"
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_TR_HOSI, G_CC_TR_HOSI),
	gsDPSetEnvColor(0xFF, 0xFF, 0x00, 0x7F),
	gsDPLoadTextureBlock(txt_tr_hosi, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0, G_TX_WRAP, G_TX_WRAP, 5, 5, 0, 0),
#include "track.tr_hosi.h"
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_OFF),
	gsSPSetGeometryMode(G_CULL_BACK|G_LIGHTING),
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsDPSetEnvColor(0xFF, 0xFF, 0xFF, 0xFF),
	gsSPEndDisplayList(),
};

static Lights1 light_rainbowroad_hosi[] =
{
	gdSPDefLight(0.25, 0xFF, 0xFF, 0xFF),
	gdSPDefLight(0.25, 0xFF, 0xFF, 0x00),
};

#include "hosi.h"

Gfx gfx_rainbowroad_hosi[] =
{
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBDECALA, G_CC_MODULATERGBDECALA),
	gsDPSetLoadTile(G_IM_FMT_RGBA, G_IM_SIZ_16b),
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_ON),
	gsDPSetImageBlock(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 5, 5, 0, 0),
	gsDPLoadImageBlock(txt_hosi_face, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32),
	gsSPSetLights1N(light_rainbowroad_hosi[0]),
#include "hosi.hosi_face.h"
	gsSPTexture(0xFFFF, 0xFFFF, G_TX_NOLOD, G_TX_RENDERTILE, G_OFF),
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsSPSetLights1N(light_rainbowroad_hosi[1]),
#include "hosi.hosi_body.h"
	gsSPEndDisplayList(),
};

#else /* SCRIPT */

extern Gfx gfx_rainbowroad_opa_surf[];
extern Gfx gfx_rainbowroad_tex_edge[];
extern Gfx gfx_rainbowroad_track[];
extern Gfx gfx_rainbowroad_hosi[];

S_SCRIPT s_rainbowroad[] =
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
			sPerspective(45, 100, 32767, s_stage_perspective),
			sStart(),
				sCamera(14, 0, 2000, 6000, 0, 0, 0, s_stage_camera),
				sStart(),
					sGfx(LAYER_OPA_SURF, gfx_rainbowroad_opa_surf),
					sGfx(LAYER_TEX_EDGE, gfx_rainbowroad_tex_edge),
					sGfx(LAYER_XLU_SURF, gfx_rainbowroad_track),
					sGfx(LAYER_OPA_SURF, gfx_rainbowroad_hosi),
					sObject(),
				sEnd(),
			sEnd(),
		sEnd(),
	sEnd(),
	sExit(),
};

#endif /* SCRIPT */
