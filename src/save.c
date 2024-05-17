#include <sm64.h>

static u8 save_mid_level;
static u8 save_mid_course;
static u8 save_mid_stage;
static u8 save_mid_scene;
static u8 save_mid_port;

u8 save_course = 0;
u8 save_level = 0;
u8 save_hiscore = FALSE;
u8 save_myscore = FALSE;
u8 save_star = 0;
u8 save_jump = FALSE;

s8 course_table[] =
{
	16,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_PSS,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
	COURSE_NULL,
};

void save_file_write(UNUSED int file)
{
}

void save_init(void)
{
	bzero(&save, sizeof(SAVE));
}

void save_reset(void)
{
	bzero(&save, sizeof(SAVE));
}

void save_set(SHORT coin, SHORT level)
{
	int file = file_index-1;
	int course = course_index-1;
	int mask = 1 << level;
	save_course = course+1;
	save_level  = level+1;
	save_hiscore = FALSE;
	save_myscore = FALSE;
	if (course >= 0 && course < 15)
	{
		if (save_file_get_coin(file, course) < coin)
		{
			save.file[file][0].coin[course] = coin;
			save_hiscore = TRUE;
			save_myscore = TRUE;
		}
	}
	switch (stage_index)
	{
	case STAGE_BITDWA:
		if (!(save_get_flag() & (SAVE_KEY1|SAVE_KEYDOOR1)))
		{
			save_set_flag(SAVE_KEY1);
		}
		break;
	case STAGE_BITFSA:
		if (!(save_get_flag() & (SAVE_KEY2|SAVE_KEYDOOR2)))
		{
			save_set_flag(SAVE_KEY2);
		}
		break;
	case STAGE_BITSA:
		break;
	default:
		if (!(save_file_get_star(file, course) & mask))
		{
			save_file_set_star(file, course, mask);
		}
		break;
	}
}

int save_file_star_count(int file, int course)
{
	int i;
	int n = 0;
	UCHAR mask = 1;
	UCHAR star = save_file_get_star(file, course);
	for (i = 0; i < 7; i++, mask <<= 1) if (star & mask) n++;
	return n;
}

int save_file_star_range(int file, int min, int max)
{
	int n = 0;
	for (; min <= max; min++) n += save_file_star_count(file, min);
	return n + save_file_star_count(file, -1);
}

void save_set_flag(unsigned int flag)
{
	save.file[file_index-1][0].flag |= SAVE_ACTIVE | flag;
}

void save_clr_flag(unsigned int flag)
{
	save.file[file_index-1][0].flag &= ~flag;
	save.file[file_index-1][0].flag |= SAVE_ACTIVE;
}

unsigned int save_get_flag(void)
{
	if (staffp) return 0;
	return save.file[file_index-1][0].flag;
}

int save_file_get_star(int file, int course)
{
	int flag;
	if (course == -1)   flag = save.file[file][0].flag >> 24 & 0x7F;
	else                flag = save.file[file][0].star[course] & 0x7F;
	return flag;
}

void save_file_set_star(int file, int course, int flag)
{
	if (course == -1)   save.file[file][0].flag |= flag << 24;
	else                save.file[file][0].star[course] |= flag;
	save.file[file][0].flag |= SAVE_ACTIVE;
}

int save_file_get_coin(int file, int course)
{
	return save.file[file][0].coin[course];
}

int save_get_cannon(void)
{
	return (save.file[file_index-1][0].star[course_index] & 0x80) != 0;
}

void save_set_cannon(void)
{
	save.file[file_index-1][0].star[course_index] |= 0x80;
	save.file[file_index-1][0].flag |= SAVE_ACTIVE;
}

void save_set_cap(SHORT x, SHORT y, SHORT z)
{
	SAVE_FILE *file = &save.file[file_index-1][0];
	file->stage = stage_index;
	file->scene = scene_index;
	vecs_set(file->pos, x, y, z);
	save_set_flag(SAVE_LOSTCAP);
}

int save_get_cap(VECS pos)
{
	SAVE_FILE *file = &save.file[file_index-1][0];
	unsigned int flag = save_get_flag();
	if (
		file->stage == stage_index &&
		file->scene == scene_index &&
		(flag & SAVE_LOSTCAP)
	)
	{
		vecs_cpy(pos, file->pos);
		return TRUE;
	}
	return FALSE;
}

void save_init_cap(void)
{
	if (save_get_flag() & SAVE_LOSTCAP)
	{
		switch (save.file[file_index-1][0].stage)
		{
		case STAGE_SSL: save_set_flag(SAVE_CONDORCAP);  break;
		case STAGE_SL:  save_set_flag(SAVE_SNOWMANCAP);  break;
		case STAGE_TTM: save_set_flag(SAVE_MONKEYCAP); break;
		}
		save_clr_flag(SAVE_LOSTCAP);
	}
}

void save_clr_mid(void)
{
	save_mid_course = COURSE_NULL;
}

void save_set_mid(PORTINFO *p)
{
	if (p->stage & 0x80)
	{
		save_mid_level  = level_index;
		save_mid_course = course_index;
		save_mid_stage  = p->stage & 0x7F;
		save_mid_scene  = p->scene;
		save_mid_port   = p->port;
	}
}

int save_get_mid(PORTINFO *p)
{
	short result = FALSE;
	SHORT course = stage_to_course(p->stage & 0x7F);
	if (
		save_mid_course != COURSE_NULL &&
		prev_course == course &&
		save_mid_level == level_index
	)
	{
		p->stage = save_mid_stage;
		p->scene = save_mid_scene;
		p->port  = save_mid_port;
		result = TRUE;
	}
	else
	{
		save_mid_course = 0;
	}
	return result;
}
