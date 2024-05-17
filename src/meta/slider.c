#ifndef SCRIPT

extern char roulette_result;

extern O_SCRIPT o_key[];
extern O_SCRIPT o_chaser[];

void slider_proc(void)
{
	switch (object->o_state)
	{
	case 1:
		time_show();
		time_ctrl(30*30-1);
		if (!objlib_8029F95C(o_key))
		{
			obj_make_abs(object, 0, S_KEY, o_key, -1200, 3000, 2300, 0, 0, 0);
		}
		obj_make_off(
			roulette_result, 0, 80, -50, mario_obj, S_CHASER, o_chaser
		);
		if (object->o_code > 0)
		{
			game_freeze(-1, NULL);
			msg_open(171);
		}
		object->o_state++;
		break;
	case 2:
		if (object->o_code > 0) object->o_code--;
		else
		{
#if 0
			Na_BgmPlay(0, NA_BGM_COSMIC, 0);
#endif
			object->o_state++;
		}
		break;
	}
}

#else /* SCRIPT */

.globl o_slider
o_slider:
	oInit(OT_SYSTEM)
	oWhile()
		oCallback(slider_proc)
	oWend()

#endif /* SCRIPT */
