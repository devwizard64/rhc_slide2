#include <sm64.h>

static u16 txt_banner_ah[] =
{
#include "banner_ah.rgba16.h"
};

static u16 txt_banner_al[] =
{
#include "banner_al.rgba16.h"
};

static u16 txt_banner_bh[] =
{
#include "banner_bh.rgba16.h"
};

static u16 txt_banner_bl[] =
{
#include "banner_bl.rgba16.h"
};

static u16 txt_banner_ch[] =
{
#include "banner_ch.rgba16.h"
};

static u16 txt_banner_cl[] =
{
#include "banner_cl.rgba16.h"
};

static u16 txt_banner_dh[] =
{
#include "banner_dh.rgba16.h"
};

static u16 txt_banner_dl[] =
{
#include "banner_dl.rgba16.h"
};

static u16 txt_ba_cable[] =
{
#include "ba_cable.rgba16.h"
};

static u16 txt_ba_pole[] =
{
#include "ba_pole.rgba16.h"
};

static u16 txt_ch_donkey_h[] =
{
#include "ch_donkey_h.rgba16.h"
};

static u16 txt_ch_donkey_l[] =
{
#include "ch_donkey_l.rgba16.h"
};

static u16 txt_ch_kinoko_h[] =
{
#include "ch_kinoko_h.rgba16.h"
};

static u16 txt_ch_kinoko_l[] =
{
#include "ch_kinoko_l.rgba16.h"
};

static u16 txt_ch_kinopio_h[] =
{
#include "ch_kinopio_h.rgba16.h"
};

static u16 txt_ch_kinopio_l[] =
{
#include "ch_kinopio_l.rgba16.h"
};

static u16 txt_ch_kuppa_h[] =
{
#include "ch_kuppa_h.rgba16.h"
};

static u16 txt_ch_kuppa_l[] =
{
#include "ch_kuppa_l.rgba16.h"
};

static u16 txt_ch_luizi_h[] =
{
#include "ch_luizi_h.rgba16.h"
};

static u16 txt_ch_luizi_l[] =
{
#include "ch_luizi_l.rgba16.h"
};

static u16 txt_ch_mario_h[] =
{
#include "ch_mario_h.rgba16.h"
};

static u16 txt_ch_mario_l[] =
{
#include "ch_mario_l.rgba16.h"
};

static u16 txt_ch_peach_h[] =
{
#include "ch_peach_h.rgba16.h"
};

static u16 txt_ch_peach_l[] =
{
#include "ch_peach_l.rgba16.h"
};

static u16 txt_ch_teresa_h[] =
{
#include "ch_teresa_h.rgba16.h"
};

static u16 txt_ch_teresa_l[] =
{
#include "ch_teresa_l.rgba16.h"
};

static u16 txt_ch_wario_h[] =
{
#include "ch_wario_h.rgba16.h"
};

static u16 txt_ch_wario_l[] =
{
#include "ch_wario_l.rgba16.h"
};

static u16 txt_ch_yossy_h[] =
{
#include "ch_yossy_h.rgba16.h"
};

static u16 txt_ch_yossy_l[] =
{
#include "ch_yossy_l.rgba16.h"
};

static u16 txt_hosi_face[] =
{
#include "hosi_face.rgba16.h"
};

static u16 txt_tr_checker[] =
{
#include "tr_checker.rgba16.h"
};

static u8 txt_tr_hosi[] =
{
#include "tr_hosi.i8.h"
};

static u16 txt_tr_rainbow[] =
{
#include "tr_rainbow.rgba16.h"
};

#include "rainbowroad/shape.c"

MAP map_rainbowroad[] =
{
#include "rainbowroad/map.h"
	MAP_END,
};

TAG tag_rainbowroad[] =
{
	TAG(CHECKPOINT, 0,   873, 4987+100,    532, 0),
	TAG(CHECKPOINT, 0,   840, 4582+100,  -3438, 1),
	TAG(CHECKPOINT, 0,   840, 2152+100, -19848, 2),
	TAG(CHECKPOINT, 0, -7655,  811+100,    542, 3),
	TAG(CHECKPOINT, 0,  -377,  271+100,  10133, 4),
	TAG(CHECKPOINT, 0,  1191, 4862+100,   4762, 5),
	TAG_END,
};
