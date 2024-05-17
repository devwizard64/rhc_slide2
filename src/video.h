typedef struct video
{
	const char *src;
	unsigned short buf;
	short frame;
	unsigned short wd;
	unsigned short ht;
}
VIDEO;

typedef struct vidwork
{
	VIDEO *vid;
	short *buf;
	short *dst[2];
	long src;
	unsigned short pki;
	unsigned short pkn;
	unsigned short idx;
	short bit;
	short cnt;
	short frame;
	short timer;
	short win[4096];
}
VIDWORK;

extern void video_rewind(VIDWORK *work);
extern void video_init(VIDWORK *work, VIDEO *vid);
extern void *video_proc(VIDWORK *work);
