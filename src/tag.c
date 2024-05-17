#include <sm64.h>

#include "tagobj.c"

void tag_obj_load(SHORT scene, TAG *tag)
{
	object_dummy.s.scene = scene;
	object_dummy.s.group = scene;
	for (;;)
	{
		int n;
		TAG buf[5];
		OBJECT *obj;
		if (*tag == -1) break;
		n = *tag & 0x1FF;
		buf[0] = *tag++ & 0xFE00;
		buf[1] = *tag++;
		buf[2] = *tag++;
		buf[3] = *tag++;
		buf[4] = *tag++;
		if ((buf[4] >> 8 & 0xFF) != 0xFF)
		{
			obj = obj_make_abs(
				&object_dummy, 0, tag_obj_table[n].shape,
				tag_obj_table[n].script,
				buf[1], buf[2], buf[3], 0, buf[0], 0
			);
			obj->o_tag_info = buf[4];
			obj->o_actor_info = ((buf[4] & 0xFF) << 16) + (buf[4] & 0xFF00);
			obj->o_code = buf[4] & 0xFF;
			obj->actor_type = ACTORTYPE_16;
			obj->actor_flag = tag - 1;
			obj->parent = obj;
		}
	}
}
