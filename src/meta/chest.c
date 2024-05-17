#ifndef SCRIPT

static Vp chest_vp =
{{
	{4*(SCREEN_WD/2), 4*(180/2), G_MAXZ/2, 0},
	{4*(SCREEN_WD/2), 4*(SCREEN_HT/2), G_MAXZ/2, 0},
}};

void sliderchest_init(void)
{
	object->o_code = 0;
}

void sliderchest_proc(void)
{
	if (mario->key > 0) object->o_code = 1;
}

extern O_SCRIPT o_sliderchest[];
extern O_SCRIPT o_chestport[];

void chest_pss_init(void)
{
	obj_make_here(object, S_CHEST, o_sliderchest);
	object->o_v0 = 1;
	object->o_v2 = 0;
}

static void chest_proc_scene(void)
{
	hud.flag = 0;
	scene_set_vp(NULL, &chest_vp, 0x00, 0x00, 0x00);
}

static void chest_proc_shake(void)
{
	camera_8027F8B8(7);
	Na_ObjSePlay(0x40080001, object);
	chest_proc_scene();
}

static void chest_proc_0(void)
{
	if (object->o_v0 == 2)
	{
		obj_make_here(object, S_CHESTPORT, o_chestport);
		time_stop();
		Na_Solution();
		mario->key--;
		object->o_state++;
	}
}

static void chest_proc_1(void)
{
	switch (object->o_timer)
	{
	case 60:
		bgm_fadeout(NA_TIME(20*3/2));
		scene_wipe(WIPE_FADE_OUT, 20, 0x00, 0x00, 0x00);
		break;
	case 89:
		object->o_state++;
		break;
	}
}

static void chest_proc_2(void)
{
	switch (object->o_timer)
	{
	case 0:
		mario->pos[0] = -6357;
		mario->pos[1] = -4587;
		mario->pos[2] = 6000;
		mario->ang[0] = 0;
		mario->ang[1] = 0;
		mario->ang[2] = 0;
		pl_set_state(mario, PS_DEMO_0A, 194);
		scene_wipe(WIPE_FADE_IN, 20, 0x00, 0x00, 0x00);
		camera_8032DF50 = 145;
		break;
	case 59:
		object->o_state++;
		break;
	}
	chest_proc_scene();
}

static void chest_proc_3(void)
{
	switch (object->o_timer)
	{
	case 29:
		pl_set_state(mario, PS_DEMO_0F, 88);
		object->o_state++;
		break;
	}
	chest_proc_shake();
}

static void chest_proc_4(void)
{
	float scale = (100-object->o_timer) / 100.0F;
	mario->obj->s.pos[1] += scale * 5;
	mario->obj->s.pos[2] += scale * 1;
	mario->obj->s.ang[0] += (int)(scale * 0x60);
	switch (object->o_timer)
	{
	case 0:
		mario->obj->s.pos[1] += 50;
		mario->obj->s.ang[0] = 0x2000;
		break;
	case 79:
		object->o_state++;
		break;
	}
	chest_proc_shake();
}

static void chest_proc_5(void)
{
	float scale = (20-object->o_timer) / 20.0F;
	float speed = (object->o_timer+10) / 30.0F;
	mario->obj->s.pos[1] -= speed * 25;
	mario->obj->s.pos[2] += scale * 40;
	mario->obj->s.ang[0] += 0x1400;
	mario->obj->s.scale[0] = scale;
	mario->obj->s.scale[1] = scale;
	mario->obj->s.scale[2] = scale;
	switch (object->o_timer)
	{
	case 0:
		Na_ObjSePlay(0x0446A081, mario_obj);
		break;
	case 19:
		object->o_state++;
		break;
	}
	chest_proc_shake();
}

static void chest_proc_6(void)
{
	switch (object->o_timer)
	{
	case 0:
		mario->obj->s.pos[2] = 5000;
		break;
	case 40:
		pl_fade(mario, FADE_ROOF);
		break;
	}
	chest_proc_shake();
}

static void (*chest_proc_table[])(void) =
{
	chest_proc_0,
	chest_proc_1,
	chest_proc_2,
	chest_proc_3,
	chest_proc_4,
	chest_proc_5,
	chest_proc_6,
};

void chest_pss_proc(void)
{
	chest_proc_table[object->o_state]();
}

void *s_chestport_cone(int code, SHAPE *shape, UNUSED void *data)
{
	S_COORD *coord;
	switch (code)
	{
	case SC_DRAW:
		coord = (S_COORD *)shape->next;
		coord->ang[1] += 0x80;
		coord = (S_COORD *)coord->s.s.next;
		coord->ang[1] -= 0x60;
		break;
	}
	return NULL;
}

void chestport_init(void)
{
	object->o_alpha = 0;
}

void chestport_proc(void)
{
	if ((object->o_alpha += 8) > 0xFF) object->o_alpha = 0xFF;
}

#else /* SCRIPT */

.globl o_chest_pss
o_chest_pss:
	oInit(OT_DEFAULT)
	oSetFlag(O_FLAG, OF_0001)
	oGround()
	oCallback(chest_pss_init)
	oWhile()
		oCallback(chest_pss_proc)
	oWend()

.globl o_sliderchest
o_sliderchest:
	oInit(OT_ENEMYA)
	oSetFlag(O_FLAG, OF_0001)
	oGround()
	oCallback(sliderchest_init)
	oCallback(object_b_802F7C9C)
	oSetI(O_HIT_TIMER, -1)
	oWhile()
		oCallback(sliderchest_proc)
		oCallback(object_b_802F7D04)
	oWend()

.globl o_chestport
o_chestport:
	oInit(OT_ENEMYA)
	oSetFlag(O_FLAG, OF_0001)
	oGround()
	oCallback(chestport_init)
	oWhile()
		oCallback(chestport_proc)
	oWend()

#endif /* SCRIPT */
