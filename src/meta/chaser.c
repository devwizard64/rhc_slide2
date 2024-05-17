#ifndef SCRIPT

static char *brkp;
void *sbrk(long n)
{
	void *ptr = brkp;
	brkp += (n+15) & ~15;
	return ptr;
}

extern const char _cirno_vidSegmentRomStart[];
static VIDEO cirno_vid = {_cirno_vidSegmentRomStart, 2749, 20, 64, 94};

static VIDWORK chaser_vidwork;

static void *chaser_vid(VIDEO *vid)
{
	VIDWORK *work = &chaser_vidwork;
	if (!work->vid) video_init(work, vid);
	return video_proc(work);
}

extern u16 txt_wega[];
extern u16 txt_osaka[];

static void *chaser_txt(u16 *txt)
{
	return segment_to_virtual(txt);
}

void *s_chaser_txt(int code, SHAPE *shape, UNUSED void *data)
{
	Gfx *gfx = NULL;
	OBJECT *obj = (OBJECT *)s_object;
	void *txt = NULL;
	switch (code)
	{
	case SC_INIT:
		brkp = (char *)0x80400000;
		bzero(&chaser_vidwork, sizeof(VIDWORK));
		break;
	case SC_DRAW:
		shape_set_layer(shape, LAYER_TEX_EDGE);
		switch (obj->o_code)
		{
		case 1: txt = chaser_vid(&cirno_vid); break;
		case 2: txt = chaser_txt(txt_wega); break;
		case 3: txt = chaser_txt(txt_osaka); break;
		}
		gfx = gfx_alloc(sizeof(Gfx)*2);
		gSPSegment(gfx+0, 1, txt);
		gSPEndDisplayList(gfx+1);
		break;
	}
	return gfx;
}

void chaser_init(void)
{
	if (object->o_code == 0)
	{
		object->s.shape = shape_table[S_1UP];
		object_set_scale(2);
	}
}

static void chaser_proc_0(void)
{
	object->o_vel_f = 0;
	object->o_pos_y += 10;
	if (object->o_timer >= 30) object->o_state = 1;
}

static void chaser_proc_1(void)
{
	float vel_y, vel_f;
	float dx = mario_obj->o_pos_x     - object->o_pos_x;
	float dy = mario_obj->o_pos_y+120 - object->o_pos_y;
	float dz = mario_obj->o_pos_z     - object->o_pos_z;
	float dd = dx*dx+dz*dz;
	if (dd < 60*60 && dy*dy < 60*60)
	{
		mario->power_dec = -31;
		pl_set_state(mario, PS_DEMO_38, 0);
		switch (object->o_code)
		{
		case 1: object_makesound(0x243BFF81); break;
		case 3: object_makesound(0x243AFF81); break;
		}
		object->flag = 0;
		return;
	}
	objlib_8029E714(object, mario_obj, O_ANG_Y, 0x1000);
	object->o_ang_x = objlib_8029E530(
		object->o_ang_x, ATAN2(sqrtf(dd), dy), 0x1000
	);
	if (object->o_vel_f < 90) object->o_vel_f += 5;
	vel_y = object->o_vel_f * SIN(object->o_ang_x);
	vel_f = object->o_vel_f * COS(object->o_ang_x);
	object->o_pos_x += vel_f * SIN(object->o_ang_y);
	object->o_pos_y += vel_y;
	object->o_pos_z += vel_f * COS(object->o_ang_y);
}

static void (*chaser_proc_table[])(void) =
{
	chaser_proc_0,
	chaser_proc_1,
};

void chaser_proc(void)
{
	if (!collision_8032DA98)
	{
		object->flag = 0;
		return;
	}
	chaser_proc_table[object->o_state]();
}

#else /* SCRIPT */

.globl o_chaser
o_chaser:
	oInit(OT_ITEM)
	oBillboard()
	oSetFlag(O_FLAG, OF_0001)
	oCallback(chaser_init)
	oWhile()
		oCallback(chaser_proc)
	oWend()

#endif /* SCRIPT */
