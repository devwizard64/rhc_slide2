#ifndef __SM64_WEATHER_H__
#define __SM64_WEATHER_H__

typedef struct weather
{
	char flag;
	s16 frame;
	int x;
	int y;
	int z;
	int work[10];
}
WEATHER;

extern WEATHER *weatherp;
extern short lava_info[10];
extern s8 weather_code;

extern void weather_get_coord(
	VECS look,
	VECS eye,
	short *dist,
	short *angx,
	short *angy
);
extern void weather_xfm(VECS v0, VECS v1, VECS v2, SHORT angx, SHORT angy);
extern Gfx *weather_draw(int code, VECS pos, VECS look, VECS eye);
extern Gfx *lava_draw(int code, VECS pos, VECS look, VECS eye);

#endif /* __SM64_WEATHER_H__ */
