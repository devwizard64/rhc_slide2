#include <sm64.h>

#include "video.h"
#include "ext.h"

extern int pl_set_anime(PLAYER *pl, int index);
extern void camera_8027F8B8(SHORT);
extern SHORT objlib_8029E530(SHORT, SHORT, SHORT);
extern SHORT objlib_8029E714(OBJECT *, OBJECT *, SHORT, SHORT);
extern OBJECT *objlib_8029F95C(O_SCRIPT *);

extern O_SCRIPT o_slider[];

void collision_80250724(UNUSED PLAYER *pl)
{
	if (!(hud.flag & HUD_TIME))
	{
		OBJECT *obj = objlib_8029F95C(o_slider);
		obj->o_state = 1;
		if (!collision_8032DA98)
		{
			collision_8032DA98 = TRUE;
			obj->o_code = 80;
			msg_open(170);
		}
		else
		{
			menu_open(4);
		}
		game_freeze(-1, NULL);
	}
}

void collision_80250778(UNUSED PLAYER *pl)
{
	collision_8032DA98 = FALSE;
}

int pl_demo_80257EAC(PLAYER *pl)
{
	pl_set_anime(pl, pl->code);
	return 0;
}

SHORT slip_ATAN2(float y, float x)
{
	if (mario->ground->code == 4) return mario->ground->attr;
	return ATAN2(y, x);
}

float slip_sqrtf(float x)
{
	if (mario->ground->code == 4) return 2;
	return sqrtf(x);
}

void camera_80290C1C(CAMERA *cam)
{
	cam->look[0] = -6357;
	cam->look[1] = -4450;
	cam->look[2] = 6250;
	cam->pos[0] = -6357 + 720;
	cam->pos[1] = -4350;
	cam->pos[2] = 6100;
}

void camera_80290C30(UNUSED CAMERA *cam)
{
	if (mario->state == PS_DEMO_0F)
	{
		float scale;
		switch (mario->mode)
		{
		case 0:
			scale = (80-mario->timer) / 100.0F;
			cam->look[1] += scale * 2;
			cam->pos[1] -= scale;
			if (++mario->timer >= 80)
			{
				mario->timer = 0;
				mario->mode++;
			}
			break;
		case 1:
			if (++mario->timer >= 20)
			{
				mario->timer = 0;
				mario->mode++;
			}
			break;
		case 2:
			cam->look[2] += (6400-cam->look[2]) / 10;
			cam->pos[0] += (-6357-cam->pos[0]) / 10;
			cam->pos[1] += (-4100-cam->pos[1]) / 30;
			if (mario->timer < 30)
			{
				mario->timer++;
				cam->pos[2] += (5800-cam->pos[2]) / 20;
			}
			else
			{
				cam->pos[2] += (6300-cam->pos[2]) / 30;
			}
			break;
		}
	}
}

#include "meta/slider.c"
#include "meta/key.c"
#include "meta/chaser.c"
#include "meta/chest.c"
#include "meta/checkpoint.c"
