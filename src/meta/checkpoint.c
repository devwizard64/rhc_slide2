#ifndef SCRIPT

static char obsflag;

extern O_SCRIPT o_chuckya[];
extern O_SCRIPT o_130008EC[];
extern O_SCRIPT o_13003174[];
extern O_SCRIPT o_13003388[];
extern O_SCRIPT o_1300407C[];
extern O_SCRIPT o_130046DC[];
extern O_SCRIPT o_1300472C[];
extern O_SCRIPT o_13004770[];
extern O_SCRIPT o_13004EF8[];

static TAG_OBJ enemytab[] =
{
	/*  6*/	{o_130008EC, S_NULL, 0},
	/* 30*/	{o_1300472C, S_GOOMBA, 1},
	/* 30*/	{o_1300472C, S_GOOMBA, 1},
	/* 32*/	{o_13004770, S_NULL, 0},
	/* 37*/	{o_1300472C, S_GOOMBA, 0},
	/* 37*/	{o_1300472C, S_GOOMBA, 0},
	/* 39*/	{o_13003388, S_AMP, 0},
	/* 39*/	{o_13003388, S_AMP, 0},
	/* 44*/	{o_13004EF8, S_HEART, 0},
	/* 44*/	{o_13004EF8, S_HEART, 0},
	/* 46*/	{o_1300407C, S_1UP, 0},
	/* 86*/	{o_130046DC, S_FLYGUY, 1},
	/* 86*/	{o_130046DC, S_FLYGUY, 1},
	/* 35*/	{o_chuckya, S_CHUCKYA, 0},
	/*111*/	{o_13003174, S_BOBOMB, 0},
	/*154*/	{o_130046DC, S_FLYGUY, 0},
};

static void putrandomenemy(void)
{
	int count;
	for (count = 0; count < 30;)
	{
		OBJECT *obj;
		TAG_OBJ *enemy;
		BGFACE *ground;
		short x = rand();
		short z = rand();
		short y = bg_check_ground(x, 8192, z, &ground);
		if (y < -8191) continue;
		enemy = &enemytab[rand() & 15];
		obj = obj_make_abs(
			object, 0, enemy->shape, enemy->script,
			x, y+40, z, 0, ground->attr, 0
		);
		obj->o_code = enemy->code;
		count++;
	}
}

extern O_SCRIPT o_checkpoint[];

void checkpoint_init(void)
{
	O_SCRIPT *script = segment_to_virtual(o_checkpoint);
	OBJECT *root = (OBJECT *)&obj_rootlist[OT_SYSTEM];
	OBJECT *obj;
	if (object->o_code == 0)
	{
		object->o_v0 = 0;
		object->o_v1 = 0;
#if 0
		object->o_v2 = 0;
#endif
		for (obj = root->next; obj != root; obj = obj->next)
		{
			if (obj->script == script && obj->o_code != 0) object->o_v1++;
		}
	}
	else
	{
		for (obj = root->next; obj != root; obj = obj->next)
		{
			if (obj->script == script && obj->o_code == 0)
			{
				object->mem[O_V0].p = obj;
				break;
			}
		}
	}
	putrandomenemy();
}

extern O_SCRIPT o_13002F64[];

void checkpoint_proc(void)
{
	float dx = mario_obj->o_pos_x - object->o_pos_x;
	float dy = mario_obj->o_pos_y - object->o_pos_y;
	float dz = mario_obj->o_pos_z - object->o_pos_z;
	if (dx*dx + dy*dy + dz*dz < 800*800)
	{
		if (object->o_code == 0)
		{
			if (object->o_v0 == object->o_v1)
			{
				object->o_v0 = 0;
#if 0
				if (++object->o_v2 < 3)
				{
					Na_ObjSePlay(0x806AA081, object);
				}
				else
#endif
				{
					pl_fade(mario, FADE_ROOF);
				}
			}
		}
		else
		{
			OBJECT *goal = object->mem[O_V0].p;
			if (goal->o_v0 == object->o_code-1)
			{
				OBJECT *obj;
				goal->o_v0 = object->o_code;
				if ((obj = objlib_8029F95C(o_13002F64)))
				{
					BGFACE *ground;
					obj->o_pos_x = object->o_pos_x;
					obj->o_pos_y = object->o_pos_y;
					obj->o_pos_z = object->o_pos_z;
					bg_check_ground(
						obj->o_pos_x,
						obj->o_pos_y,
						obj->o_pos_z,
						&ground
					);
					if (ground && ground->code == 4)
					{
						obj->o_ang_y = ground->attr;
					}
				}
				switch (object->o_code)
				{
				case 1:
					if (!obsflag)
					{
						obsflag = TRUE;
						ExtShowOBSError();
					}
					break;
				case 5:
					break;
				default:
					switch (rand() & 1)
					{
					case 0: ExtMoveWindow();    break;
					case 1: ExtColorKey();      break;
					}
					break;
				}
			}
		}
	}
}

#else /* SCRIPT */

.globl o_checkpoint
o_checkpoint:
	oInit(OT_SYSTEM)
	oCallback(checkpoint_init)
	oWhile()
		oCallback(checkpoint_proc)
	oWend()

#endif /* SCRIPT */
