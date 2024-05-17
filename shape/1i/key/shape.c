#ifndef SCRIPT

UNUSED static long long align_key0 = 0;

static Lights1 light_key[] =
{
	gdSPDefLight(0.25, 0xFF, 0x64, 0x32),
	gdSPDefLight(0.25, 0x32, 0xFF, 0x64),
	gdSPDefLight(0.25, 0x32, 0x64, 0xFF),
	gdSPDefLight(0.25, 0xCC, 0xFF, 0x00),
};

UNUSED static long long align_key1 = 0;

#include "key.h"

static Gfx gfx_key_key[] =
{
#include "key.key.h"
	gsSPEndDisplayList(),
};

Gfx gfx_key_b[] =
{
	gsSPSetLights1(light_key[2]),
	gsSPBranchList(gfx_key_key),
};

Gfx gfx_key_g[] =
{
	gsSPSetLights1(light_key[1]),
	gsSPBranchList(gfx_key_key),
};

Gfx gfx_key_r[] =
{
	gsSPSetLights1(light_key[0]),
	gsSPBranchList(gfx_key_key),
};

Gfx gfx_key[] =
{
	gsSPSetLights1(light_key[3]),
	gsSPBranchList(gfx_key_key),
};

#else /* SCRIPT */

extern Gfx gfx_key[];

S_SCRIPT s_key[] =
{
	sShadow(80, 150, SHADOW_CIRCLE4),
	sStart(),
		sScale(0.25),
		sStart(),
			sGfx(LAYER_OPA_SURF, gfx_key), // 0x05006A68
		sEnd(),
	sEnd(),
	sExit(),
};

#endif /* SCRIPT */
