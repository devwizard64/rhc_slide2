#ifndef __SM64_TAG_H__
#define __SM64_TAG_H__

#define TAG_START               0
#define TAG_END                 (TAG_START+(-1))

#define TAG(tag, angy, posx, posy, posz, code) \
	(TAG)((TAG_START+TAG_##tag) | (angy) << 9), posx, posy, posz, (u8)(code)

typedef struct tag_obj
{
	O_SCRIPT *script;
	s16 shape;
	s16 code;
}
TAG_OBJ;

extern void tag_obj_load(SHORT scene, TAG *tag);

#endif /* __SM64_TAG_H__ */
