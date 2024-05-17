#include <sm64.h>

#include "exec.h"
#include "ext.h"

#define CHANGE_NULL             0
#define CHANGE_STAGE            1
#define CHANGE_SCENE            2
#define CHANGE_PORT             3

#define GM_NORMAL               0
#define GM_PAUSE                2
#define GM_FREEZE               3
#define GM_EXIT                 4
#define GM_FRAMEADV             5

#include "staff.c"

static STAFF staff_table[] =
{
	{STAGE_GROUNDS, 1, 1,               -0x80,     0,  8000,     0, NULL},
	{STAGE_BOB,     1, 1|STAFF_TL|0x00,  0x75,   713,  3918, -3889, staff_01},
	{STAGE_WF,      1, 2|STAFF_BR|0x00,  0x2E,   347,  5376,   326, staff_02},
	{STAGE_JRB,     1, 2|STAFF_TR|0x00,  0x16,  3800, -4840,  2727, staff_03},
	{STAGE_CCM,     2, 2|STAFF_BL|0x00,  0x19, -5464,  6656, -6575, staff_04},
	{STAGE_BBH,     1, 1|STAFF_TL|0x00,  0x3C,   257,  1922,  2580, staff_05},
	{STAGE_HMC,     1, 1|STAFF_BR|0xC0,  0x7B, -6469,  1616, -6054, staff_06},
	{STAGE_THI,     3, 1|STAFF_TR|0x00, -0x20,   508,  1024,  1942, staff_07},
	{STAGE_LLL,     2, 1|STAFF_BL|0x00,  0x7C,   -73,    82, -1467, staff_08},
	{STAGE_SSL,     1, 1|STAFF_TL|0x40,  0x62, -5906,  1024, -2576, staff_09},
	{STAGE_DDD,     1, 2|STAFF_BR|0x00,  0x2F, -4884, -4607,  -272, staff_10},
	{STAGE_SL,      1, 1|STAFF_TR|0x00, -0x22,  1925,  3328,   563, staff_11},
	{STAGE_WDW,     1, 1|STAFF_BL|0x00,  0x69,  -537,  1850,  1818, staff_12},
	{STAGE_TTM,     1, 2|STAFF_TL|0x00, -0x21,  2613,   313,  1074, staff_13},
	{STAGE_THI,     1, 3|STAFF_BR|0x00,  0x36, -2609,   512,   856, staff_14},
	{STAGE_TTC,     1, 1|STAFF_TR|0x00, -0x48, -1304,   -71,  -967, staff_15},
	{STAGE_RR,      1, 1|STAFF_BL|0x00,  0x40,  1565,  1024,  -148, staff_16},
	{STAGE_SA,      1, 1|STAFF_TL|0x00,  0x18, -1050, -1330, -1559, staff_17},
	{STAGE_COTMC,   1, 1|STAFF_BR|0x00, -0x10,  -254,   415, -6045, staff_18},
	{STAGE_DDD,     2, 1|STAFF_TR|0x80, -0x40,  3948,  1185,  -104, staff_19},
	{STAGE_CCM,     1, 1|STAFF_BL|0x00,  0x1F,  3169, -4607,  5240, staff_20},
	{STAGE_GROUNDS, 1, 1,               -0x80,     0,   906, -1200, NULL},
	{STAGE_NULL,    0, 1,                0x00,     0,     0,     0, NULL},
};

HUD hud;
PLAYER player_data[1];
PLAYER *mario = &player_data[0];

static s16 game_state;
static s16 game_timer;

static short freeze_timer;
static FREEZECALL *freeze_callback;

static PL_ENTRY mario_entry;
static s16 game_result;

static s16 fade_mode;
static s16 fade_timer;
static s16 fade_port;
static u32 fade_code;

UNUSED static s16 game_8032D940 = 0;
UNUSED static s16 game_8033B25C;
static char time_flag;
static char mid_flag = FALSE;

char first_msg;

static void game_sceneproc(short *);

int time_ctrl(int code)
{
	switch (code)
	{
	case 0:
		hud.flag |= HUD_TIME;
		time_flag = 0;
		hud.time = 0;
		break;
	case 1:
		time_flag = 1;
		break;
	case 2:
		time_flag = 0;
		break;
	case 3:
		hud.flag &= ~HUD_TIME;
		time_flag = 0;
		hud.time = 0;
		break;
	default:
		time_flag = -1;
		hud.time = code;
		break;
	}
	return hud.time;
}

static int game_checkpause(void)
{
	int msgopen = msg_get() >= 0;
	int demo = (mario->state & PF_DEMO) != 0;
	if (!(demo || msgopen || wipe.active || fade_mode != FADE_NULL))
	{
		if (cont1->down & START_BUTTON) return TRUE;
	}
	return FALSE;
}

static void game_set_state(SHORT state)
{
	game_state = state;
	game_timer = 0;
}

static void game_exit(int code)
{
	game_state = GM_EXIT;
	game_timer = 0;
	game_result = code;
}

void game_fadeout(int code, int color)
{
	if (color) color = 0xFF;
	aud_fadeout(NA_TIME(16*3/2));
	scene_wipe(WIPE_FADE_OUT, 16, color, color, color);
	game_freeze(30, NULL);
	game_exit(code);
}

UNUSED
static void game_8024982C(void)
{
}

void game_init_msg(int index)
{
	int flag;
	int msg = scenep->msg[index];
	switch (msg)
	{
	case 129: flag = save_get_flag() & SAVE_BLUESW;     break;
	case 130: flag = save_get_flag() & SAVE_GREENSW;    break;
	case 131: flag = save_get_flag() & SAVE_REDSW;      break;
	case 255: flag = TRUE;                              break;
	default:  flag = save_get_star(course_index-1);     break;
	}
	if (!flag)
	{
		game_freeze(-1, NULL);
		msg_open(msg);
	}
}

static void pl_init_door(ACTOR *actor, u32 code)
{
	if (code & 2) actor->ang[1] += 0x8000;
#ifdef sgi
	actor->pos[0] += 300 * SIN(actor->ang[1]);
	actor->pos[2] += 300 * COS(actor->ang[1]);
#else
	actor->pos[0] += (int)(300 * SIN(actor->ang[1]));
	actor->pos[2] += (int)(300 * COS(actor->ang[1]));
#endif
}

#if 0
static void pl_init_cap(PLAYER *pl)
{
	int index = course_index - COURSE_CAPSW;
	switch (index)
	{
	case COURSE_COTMC - COURSE_CAPSW:
		pl->flag |= PL_00000010|PL_00000004;
		pl->cap_timer = 30*20;
		break;
	case COURSE_TOTWC - COURSE_CAPSW:
		pl->flag |= PL_00000010|PL_00000008;
		pl->cap_timer = 30*40;
		break;
	case COURSE_VCUTM - COURSE_CAPSW:
		pl->flag |= PL_00000010|PL_00000002;
		pl->cap_timer = 30*20;
		break;
	}
}
#endif

static void pl_init_state(PLAYER *pl, int type, u32 code)
{
	switch (type)
	{
	case ENTER_DOOR:    pl_set_state(pl, PS_DEMO_22, code); break;
	case ENTER_02:      pl_set_state(pl, PS_WAIT_01, 0); break;
	case ENTER_03:      pl_set_state(pl, PS_DEMO_23, 0); break;
	case ENTER_04:      pl_set_state(pl, PS_DEMO_37, 0); break;
	case ENTER_10:      pl_set_state(pl, PS_WAIT_01, 0); break;
	case ENTER_12:      pl_set_state(pl, PS_DEMO_32, 0); break;
	case ENTER_13:      pl_set_state(pl, PS_JUMP_33, 0); break;
	case ENTER_14:      pl_set_state(pl, PS_DEMO_24, 0); break;
	case ENTER_15:      pl_set_state(pl, PS_DEMO_2A, 0); break;
	case ENTER_16:      pl_set_state(pl, PS_DEMO_24, 0); break;
	case ENTER_17:      pl_set_state(pl, PS_JUMP_19, 2); break;
	case ENTER_11:      pl_set_state(pl, PS_SWIM_00, 1); break;
	case ENTER_20:      pl_set_state(pl, PS_DEMO_26, 0); break;
	case ENTER_21:      pl_set_state(pl, PS_DEMO_28, 0); break;
	case ENTER_22:      pl_set_state(pl, PS_DEMO_2D, 0); break;
	case ENTER_23:      pl_set_state(pl, PS_DEMO_29, 0); break;
	case ENTER_24:      pl_set_state(pl, PS_DEMO_2B, 0); break;
	case ENTER_25:      pl_set_state(pl, PS_DEMO_2C, 0); break;
	}
#if 0
	pl_init_cap(pl);
#endif
}

static void game_init_port(void)
{
	PORT *port = port_get(mario_entry.port);
	int type = port_get_type(port->obj);
	if (mario->state != PS_NULL)
	{
		player_actor[0].pos[0] = port->obj->o_pos_x;
		player_actor[0].pos[1] = port->obj->o_pos_y;
		player_actor[0].pos[2] = port->obj->o_pos_z;
		player_actor[0].ang[0] = 0;
		player_actor[0].ang[1] = port->obj->o_ang_y;
		player_actor[0].ang[2] = 0;
		if (type == ENTER_DOOR)
		{
			pl_init_door(&player_actor[0], mario_entry.code);
		}
		if (
			mario_entry.type == CHANGE_STAGE ||
			mario_entry.type == CHANGE_SCENE
		)
		{
			player_actor[0].scene = mario_entry.scene;
			scene_player_open();
		}
		player_80254B20();
		pl_init_state(mario, type, mario_entry.code);
		mario->collide = port->obj;
		mario->attach = port->obj;
	}
	camera_80286F68(scenep->cam);
	mario_entry.type = CHANGE_NULL;
	fade_mode = FADE_NULL;
	switch (type)
	{
	case ENTER_03:      scene_wipe(WIPE_STAR_IN,   16, 0x00, 0x00, 0x00); break;
	case ENTER_DOOR:    scene_wipe(WIPE_CIRCLE_IN, 16, 0x00, 0x00, 0x00); break;
	case ENTER_04:      scene_wipe(WIPE_FADE_IN,   20, 0xFF, 0xFF, 0xFF); break;
	case ENTER_16:      scene_wipe(WIPE_FADE_IN,   26, 0xFF, 0xFF, 0xFF); break;
	case ENTER_14:      scene_wipe(WIPE_CIRCLE_IN, 16, 0x00, 0x00, 0x00); break;
	case ENTER_27:      scene_wipe(WIPE_FADE_IN,   16, 0x00, 0x00, 0x00); break;
	default:            scene_wipe(WIPE_STAR_IN,   16, 0x00, 0x00, 0x00); break;
	}
	bgm_play(scenep->bgm_mode, scenep->bgm, 0);
	if (mario->flag & PL_00000004) bgm_special_play(NA_BGM_METAL);
	if (mario->flag & (PL_00000002|PL_00000008))
	{
		bgm_special_play(NA_BGM_SPECIAL);
	}
#if REVISION > 199606
	if (stage_index == STAGE_BOB)
	{
		if (Na_BgmGet() != NA_BGM_RACE && time_flag)
		{
			Na_BgmPlay(0, NA_BGM_RACE, 0);
		}
	}
#endif
}

static void game_proc_entry(void)
{
	if (mario_entry.type != CHANGE_NULL)
	{
		if (mario_entry.type == CHANGE_SCENE)
		{
			time_hide();
			scene_player_close();
			scene_open(mario_entry.scene);
			if (stage_index == STAGE_PSS) mario->key = 0;
		}
		game_init_port();
	}
}

static void game_init_stage(void)
{
	stage_index = mario_entry.stage;
	time_hide();
	scene_open(mario_entry.scene);
	game_init_port();
}

static void game_init_staff(void)
{
	u32 state;
	switch (mario_entry.port)
	{
	case PORT_FINAL:    state = PS_DEMO_18; break;
	case PORT_STAFF:    state = PS_DEMO_19; break;
	case PORT_STAFFEND: state = PS_DEMO_1A; break;
#ifdef __GNUC__
	default: __builtin_unreachable();
#endif
	}
	stage_index = mario_entry.stage;
	scene_open(mario_entry.scene);
	vecs_set(player_actor[0].pos, staffp->posx, staffp->posy, staffp->posz);
	vecs_set(player_actor[0].ang, 0, staffp->angy << 8, 0);
	player_actor[0].scene = mario_entry.scene;
	scene_player_open();
	player_80254B20();
	pl_set_state(mario, state, 0);
	camera_80286F68(scenep->cam);
	mario_entry.type = CHANGE_NULL;
	fade_mode = FADE_NULL;
	scene_wipe(WIPE_FADE_IN, 20, 0x00, 0x00, 0x00);
	if (!staffp || staffp == staff_table)
	{
		bgm_play(scenep->bgm_mode, scenep->bgm, 0);
	}
}

static void game_proc_connect(void)
{
	short _02;
	BGFACE *ground;
	if (stage_index == STAGE_INSIDE && save_star_total() >= 70) return;
	if ((ground = mario->ground))
	{
		int index = ground->code - BG_CONNECT;
		if (index >= 0 && index < 4 && scenep->connect) /* T:def */
		{
			CONNECT *connect = &scenep->connect[index];
			if (connect->flag)
			{
				mario->pos[0] += connect->offset[0];
				mario->pos[1] += connect->offset[1];
				mario->pos[2] += connect->offset[2];
				mario->obj->o_pos_x = mario->pos[0];
				mario->obj->o_pos_y = mario->pos[1];
				mario->obj->o_pos_z = mario->pos[2];
				_02 = mario->scene->cam->_02;
				scene_set(connect->scene);
				mario->scene = scenep;
				camera_8028C7A0(
					connect->offset[0], connect->offset[1], connect->offset[2]
				);
				mario->scene->cam->_02 = _02;
			}
		}
	}
}

static int game_is_same_bgm(SHORT port)
{
	PORT *portp = port_get(port);
	SHORT stage = portp->p.stage & 0x7F;
#if REVISION <= 199606
	USHORT mode = scene_table[portp->p.scene].bgm_mode;
	USHORT bgm  = scene_table[portp->p.scene].bgm;
	SHORT result =
		stage == stage_index && mode == scenep->bgm_mode && bgm == scenep->bgm;
	if (Na_BgmGet() != bgm) result = FALSE;
#else
	SHORT scene = portp->p.scene;
	SHORT result = TRUE;
	if (stage == STAGE_BOB && stage == stage_index && scene == scene_index)
	{
		SHORT bgm = Na_BgmGet();
		if (bgm == NA_BGM_SHELL || bgm == NA_BGM_SPECIAL) result = FALSE;
	}
	else
	{
		USHORT mode = scene_table[scene].bgm_mode;
		USHORT bgm  = scene_table[scene].bgm;
		result =
			stage == stage_index &&
			mode == scenep->bgm_mode && bgm == scenep->bgm;
		if (Na_BgmGet() != bgm) result = FALSE;
	}
#endif
	return result;
}

static void game_set_entry(SHORT stage, SHORT scene, SHORT port, u32 code)
{
	if      (port >= PORT_FINAL)        mario_entry.type = CHANGE_STAGE;
	else if (stage != stage_index)      mario_entry.type = CHANGE_STAGE;
	else if (scene != scenep->index)    mario_entry.type = CHANGE_SCENE;
	else if (stage == STAGE_PSS)        mario_entry.type = CHANGE_SCENE;
	else                                mario_entry.type = CHANGE_PORT;
	mario_entry.stage = stage;
	mario_entry.scene = scene;
	mario_entry.port = port;
	mario_entry.code = code;
}

static BGPORT *bgport_get(void)
{
	BGPORT *bgport = NULL;
	int index = mario->ground->code - 211; /* T:bgcode */
	if (index >= 0 && index < 3*15) /* T:def */
	{
		if (index < 3*14 || mario->pos[1]-mario->ground_y < 80) /* T:def */
		{
			bgport = &scenep->bgport[index];
		}
	}
	return bgport;
}

static void game_proc_bgport(void)
{
	BGPORT bgport, *bgportp;
	if (scenep->bgport && mario->ground)
	{
		if ((bgportp = bgport_get()) != NULL)
		{
			if (mario->state & PF_DEMO)
			{
				aud_wave_sound();
			}
			else if (bgportp->p.attr)
			{
				bgport = *bgportp;
				if (!(bgport.p.stage & 0x80))
				{
					mid_flag = save_get_mid(&bgport.p);
				}
				game_set_entry(
					bgport.p.stage & 0x7F, bgport.p.scene, bgport.p.port, 0
				);
				save_set_mid(&bgport.p);
				scene_wipe_delay(WIPE_FADE_OUT, 30, 0xFF, 0xFF, 0xFF, 45);
				game_freeze(45+30-1, game_sceneproc);
				pl_set_state(mario, PS_DEMO_00, 0);
				mario->obj->s.s.flag &= ~SHP_ACTIVE;
				Na_FixSePlay(NA_SE7_1E);
				aud_fadeout(NA_TIME(50));
			}
		}
	}
}

int pl_fade(PLAYER *pl, int mode)
{
	int fadeout = TRUE;
	if (fade_mode == FADE_NULL)
	{
		pl->invincible = -1;
		fade_code = 0;
		fade_mode = mode;
		switch (mode)
		{
		case FADE_LOGO:
		case FADE_FACE:
			fade_timer = 20;
			fade_port = PORT_WIN;
			prev_course = 0;
			fadeout = FALSE;
			scene_wipe(WIPE_STAR_OUT, 20, 0x00, 0x00, 0x00);
			break;
		case FADE_ENDING:
			fade_timer = 60;
			fade_port = PORT_WIN;
			fadeout = FALSE;
			prev_course = 0;
			scene_wipe(WIPE_FADE_OUT, 60, 0x00, 0x00, 0x00);
			break;
		case FADE_WIN:
			fade_timer = 32;
			fade_port = PORT_WIN;
			prev_course = 0;
			scene_wipe(WIPE_MARIO_OUT, 32, 0x00, 0x00, 0x00);
			break;
		case FADE_DIE:
			if (pl->life == 0) fade_mode = FADE_GAMEOVER;
			fade_timer = 48;
			fade_port = PORT_DIE;
			scene_wipe(WIPE_BOWSER_OUT, 48, 0x00, 0x00, 0x00);
			Na_FixSePlay(NA_SE7_18);
			break;
		case FADE_FALL:
			fade_port = PORT_FALL;
			if (!port_get(fade_port))
			{
				if (pl->life == 0)  fade_mode = FADE_GAMEOVER;
				else                fade_port = PORT_DIE;
			}
			fade_timer = 20;
			scene_wipe(WIPE_CIRCLE_OUT, 20, 0x00, 0x00, 0x00);
			break;
		case FADE_ROOF:
			fade_timer = 30;
			fade_port = PORT_ROOF;
			scene_wipe(WIPE_FADE_OUT, 30, 0xFF, 0xFF, 0xFF);
#if REVISION > 199606
			Na_FixSePlay(NA_SE7_1E);
#endif
			break;
		case FADE_2:
			fade_timer = 30;
			fade_port = obj_get_code(pl->attach);
			scene_wipe(WIPE_FADE_OUT, 30, 0xFF, 0xFF, 0xFF);
			break;
		case FADE_5:
			fade_timer = 20;
			fade_port = obj_get_code(pl->attach);
			fadeout = !game_is_same_bgm(fade_port);
			scene_wipe(WIPE_FADE_OUT, 20, 0xFF, 0xFF, 0xFF);
			break;
		case FADE_DOOR:
			fade_timer = 20;
			fade_code = pl->code;
			fade_port = obj_get_code(pl->attach);
			fadeout = !game_is_same_bgm(fade_port);
			scene_wipe(WIPE_CIRCLE_OUT, 20, 0x00, 0x00, 0x00);
			break;
		case FADE_PIPE:
			fade_timer = 20;
			fade_port = obj_get_code(pl->attach);
			fadeout = !game_is_same_bgm(fade_port);
			scene_wipe(WIPE_STAR_OUT, 20, 0x00, 0x00, 0x00);
			break;
		case FADE_FINAL:
			fade_timer = 30;
			scene_wipe(WIPE_FADE_OUT, 30, 0x00, 0x00, 0x00);
			break;
		case FADE_STAFF:
			if (staffp == staff_table)
			{
				fade_timer = 60;
				scene_wipe(WIPE_FADE_OUT, 60, 0x00, 0x00, 0x00);
			}
			else
			{
				fade_timer = 20;
				scene_wipe(WIPE_FADE_OUT, 20, 0x00, 0x00, 0x00);
			}
			fadeout = FALSE;
			break;
		}
		if (fadeout) aud_fadeout(NA_TIME(fade_timer*3/2));
	}
	return fade_timer;
}

static void game_proc_fade(void)
{
	PORT *portp;
	int port;
	if (fade_mode != FADE_NULL && --fade_timer == 0)
	{
		msg_close();
		if (debug_stage && (fade_mode & FADE_EXIT))
		{
			game_exit(EXIT_DEBUG);
		}
		else
		{
			switch (fade_mode)
			{
			case FADE_GAMEOVER:
				save_reset();
				game_exit(EXIT_GAMEOVER);
				break;
			case FADE_ENDING:
				game_exit(EXIT_ENDING);
				Na_EndingUnlockSe();
				break;
			case FADE_FACE:
				game_exit(EXIT_FACE);
				break;
			case FADE_FINAL:
				staffp = staff_table;
				game_set_entry(staffp->stage, staffp->scene, PORT_FINAL, 0);
				break;
			case FADE_STAFF:
				Na_StaffLockSe();
				staffp++;
				level_index = staffp->flag & 7;
				port = (staffp+1)->stage == STAGE_NULL ?
					PORT_STAFFEND : PORT_STAFF;
				game_set_entry(staffp->stage, staffp->scene, port, 0);
				break;
			default:
				portp = port_get(fade_port);
				game_set_entry(
					portp->p.stage & 0x7F, portp->p.scene, portp->p.port,
					fade_code
				);
				save_set_mid(&portp->p);
				if (mario_entry.type != CHANGE_STAGE)
				{
					game_freeze(2, NULL);
				}
				break;
			}
		}
	}
}

static void game_proc_hud(void)
{
	if (!staffp && hud.flag)
	{
		SHORT power = mario->power > 0 ? mario->power >> 8 : 0;
		if (course_index > 0)   hud.flag |= HUD_COIN;
		else                    hud.flag &= ~HUD_COIN;
		if (hud.coin < mario->coin && (gfx_frame & 1))
		{
			Na_Se se = (mario->state & (PF_SWIM|PF_SINK)) ?
				NA_SE3_12 : NA_SE3_11;
			hud.coin++;
			Na_ObjSePlay(se, mario->obj);
		}
		if (mario->life > 100) mario->life = 100;
#if REVISION <= 199606
		if (mario->coin > 999) mario->life = (s8)999;
#else
		if (mario->coin > 999) mario->coin = 999;
		if (hud.coin    > 999) hud.coin    = 999;
#endif
		hud.star = mario->star;
		hud.life = mario->life;
		hud.key  = mario->key;
		if (power > hud.power) Na_FixSePlay(NA_SE7_0D);
		hud.power = power;
		if (mario->power_dec > 0)   hud.flag |= HUD_ALERT;
		else                        hud.flag &= ~HUD_ALERT;
	}
}

static void game_sceneproc(UNUSED short *timer)
{
	scene_proc();
	game_proc_hud();
	if (scenep) camera_802868F8(scenep->cam);
}

static int game_proc_normal(void)
{
	game_proc_entry();
	game_proc_connect();
	if (time_flag > 0 && hud.time < 30*60*10-1) hud.time++;
	if (time_flag < 0 && hud.time > 0)
	{
		if (--hud.time == 0)
		{
			if (mario->state == PS_WAIT_27)
			{
				mario->cont->held |= D_CBUTTONS;
				mario->cont->down |= D_CBUTTONS;
			}
			pl_fade(mario, FADE_FALL);
		}
	}
	if (fade_mode == FADE_FALL)
	{
		mario->cont->held &= ~U_CBUTTONS;
		mario->cont->down &= ~U_CBUTTONS;
	}
	scene_proc();
	game_proc_hud();
	if (scenep) camera_802868F8(scenep->cam);
	game_proc_bgport();
	game_proc_fade();
	if (game_state == GM_NORMAL)
	{
		if (mario_entry.type == CHANGE_STAGE)
		{
			game_set_state(GM_EXIT);
		}
		else if (freeze_timer != 0)
		{
			game_set_state(GM_FREEZE);
		}
		else if (game_checkpause())
		{
			aud_set_mute(AUD_PAUSE);
			camera_8033C848 |= 0x8000;
			game_set_state(GM_PAUSE);
		}
	}
	return 0;
}

static int game_proc_pause(void)
{
	if (msg_status == 0)
	{
		menu_open(1);
	}
	else if (msg_status == 1)
	{
		aud_clr_mute(AUD_PAUSE);
		camera_8033C848 &= ~0x8000;
		game_set_state(GM_NORMAL);
	}
	else
	{
		if (debug_stage)
		{
			game_fadeout(EXIT_DEBUG, 1);
		}
		else
		{
			game_fadeout(EXIT_LOGO, 0);
			prev_course = 0;
		}
		camera_8033C848 &= ~0x8000;
	}
	return 0;
}

static int game_proc_frameadv(void)
{
	if (cont1->down & D_JPAD)
	{
		camera_8033C848 &= ~0x8000;
		game_proc_normal();
	}
	else if (cont1->down & START_BUTTON)
	{
		camera_8033C848 &= ~0x8000;
		aud_clr_mute(AUD_PAUSE);
		game_set_state(GM_NORMAL);
	}
	else
	{
		camera_8033C848 |= 0x8000;
	}
	return 0;
}

void game_freeze(SHORT timer, FREEZECALL *callback)
{
	freeze_timer = timer;
	freeze_callback = callback;
}

static int game_proc_freeze(void)
{
	if (freeze_callback == (FREEZECALL *)-1) camera_802868F8(scenep->cam);
	else if (freeze_callback) freeze_callback(&freeze_timer);
	if (freeze_timer > 0) freeze_timer--;
	if (freeze_timer == 0)
	{
		freeze_callback = NULL;
		game_set_state(GM_NORMAL);
	}
	return 0;
}

static int game_proc_exit(void)
{
	if (freeze_callback) freeze_callback(&freeze_timer);
	if (--freeze_timer == -1)
	{
		hud.flag = 0;
		freeze_timer = 0;
		freeze_callback = NULL;
		if (mario_entry.type != CHANGE_NULL) return mario_entry.stage;
		else return game_result;
	}
	return 0;
}

UNUSED
static int game_proc_exit_old(void)
{
	if (--freeze_timer == -1)
	{
		hud.flag = 0;
		if (mario_entry.type != CHANGE_NULL) return mario_entry.stage;
		else return game_result;
	}
	return 0;
}

static int game_proc(void)
{
	int result;
	switch (game_state)
	{
	case GM_NORMAL:     result = game_proc_normal();    break;
	case GM_PAUSE:      result = game_proc_pause();     break;
	case GM_FREEZE:     result = game_proc_freeze();    break;
	case GM_EXIT:       result = game_proc_exit();      break;
	case GM_FRAMEADV:   result = game_proc_frameadv();  break;
#ifdef __GNUC__
	default: __builtin_unreachable();
#endif
	}
	if (result != 0)
	{
		aud_reset_mute();
		aud_unlock();
	}
	return result;
}

static int game_init(void)
{
	game_set_state(GM_NORMAL);
	fade_mode = FADE_NULL;
	freeze_timer = 0;
	game_result = 0;
	hud.flag = !staffp ? (HUD_ALL & ~HUD_TIME) : 0;
	time_flag = 0;
	if (mario_entry.type != CHANGE_NULL)
	{
		if (mario_entry.port >= PORT_FINAL) game_init_staff();
		else                                game_init_stage();
	}
	else
	{
		if (player_actor[0].scene >= 0)
		{
			scene_player_open();
			player_80254B20();
		}
		if (scenep)
		{
			camera_80286F68(scenep->cam);
			if (!debug_stage && mario->state != PS_NULL)
			{
				pl_set_state(mario, PS_WAIT_01, 0);
			}
		}
		scene_wipe(WIPE_FADE_IN, 16, 0xFF, 0xFF, 0xFF);
		bgm_play(scenep->bgm_mode, scenep->bgm, 0);
	}
	return 1;
}

long game_process(SHORT code, UNUSED long status)
{
	int result = 0;
	switch (code)
	{
	case 0: result = game_init(); break;
	case 1: result = game_proc(); break;
#ifdef __GNUC__
	default: __builtin_unreachable();
#endif
	}
	return result;
}

long game_initialize(UNUSED SHORT code, long status)
{
	mario_entry.type = CHANGE_NULL;
	fade_mode = FADE_NULL;
	first_msg = FALSE;
	stage_index = status;
	course_index = COURSE_NULL;
	prev_course = COURSE_NULL;
	staffp = NULL;
	save_jump = FALSE;
	player_80254F44();
	save_clr_mid();
	save_init_cap();
	camera_80287BC4();
	object_b_802E3E50();
	return status;
}

long game_checkselect(UNUSED SHORT code, long status)
{
	static char flag;
	int mid = mid_flag;
	mid_flag = FALSE;
	stage_index = status;
	course_index = stage_to_course(status);
	if (stage_index == 1 && !flag)
	{
		flag = TRUE;
		if (extinit() > 0) return TRUE;
	}
	if (staffp || course_index == COURSE_NULL) return FALSE;
	if (!(
		stage_index == STAGE_BITDWA ||
		stage_index == STAGE_BITFSA ||
		stage_index == STAGE_BITSA
	))
	{
		mario->coin = 0;
		hud.coin = 0;
		save_star = save_get_star(course_index-1);
	}
	if (prev_course != course_index)
	{
		prev_course = course_index;
		course_init();
		save_clr_mid();
	}
	if (course_index >= COURSE_EXTRA || mid) return FALSE;
	if (debug_stage && !debug_time) return FALSE;
	return FALSE;
}

static u64 game_getkey(void)
{
	u32 data[2];
	osPiReadIo(0x10, &data[0]);
	osPiReadIo(0x14, &data[1]);
	return (u64)data[0] << 32 | data[1];
}

static u64 game_getsave(void)
{
	u64 data;
	osEepromRead(&si_mq, 0, (u8 *)&data);
	return data;
}

static void game_setsave(u64 data)
{
	osEepromWrite(&si_mq, 0, (u8 *)&data);
}

long game_checksave(SHORT code, UNUSED long status)
{
	if (eeprom_status)
	{
		if (game_getsave() == game_getkey())
		{
			game_setsave(~0);
			return 1;
		}
	}
	return code;
}

long game_error(SHORT code, UNUSED long status)
{
	const char *str;
	switch (code)
	{
	case 0:
		if (eeprom_status) game_setsave(game_getkey());
		Na_FixSePlay(NA_SE7_0E);
		break;
	case 1:
		dprintc(SCREEN_WD/2, 200-8, "CORE VERSION ERROR");
		dprintc(SCREEN_WD/2, 150-8, "PLEASE UPDATE TO THE");
		dprintc(SCREEN_WD/2, 130-8, "LATEST VERSION OF");
		dprintc(SCREEN_WD/2, 110-8, "PARALLELN64");
		dprintc(SCREEN_WD/2,  60-8, "YOUR PROGRESS");
		str = eeprom_status ? "HAS BEEN SAVED" : "COULD NOT BE SAVED";
		dprintc(SCREEN_WD/2,  40-8, str);
		break;
	}
	return 0;
}

long ending_proc(SHORT code, UNUSED long status)
{
	switch (code)
	{
	case 0:
		break;
	case 1:
		if (execflag) ExtExecDolphin();
		break;
	}
	return 0;
}
