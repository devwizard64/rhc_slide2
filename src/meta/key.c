#ifndef SCRIPT

void key_init(void)
{
	object_set_scale(2);
}

void key_proc(void)
{
	float dx = mario_obj->o_pos_x - object->o_pos_x;
	float dy = mario_obj->o_pos_y - object->o_pos_y;
	float dz = mario_obj->o_pos_z - object->o_pos_z;
	if (dx*dx + dz*dz < 100*100 && dy*dy < 150*150)
	{
		Na_ObjSePlay(0x806AA081, object);
		mario->key++;
		object->flag = 0;
	}
	object->o_shape_ang_y += (object->o_v0 += 0x1000) & 0x1000;
}

#else /* SCRIPT */

.globl o_key
o_key:
	oInit(OT_ITEM)
	oSetFlag(O_FLAG, OF_0001)
	oCallback(key_init)
	oWhile()
		oCallback(key_proc)
	oWend()

#endif /* SCRIPT */
