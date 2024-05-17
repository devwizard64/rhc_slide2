#include <sm64.h>

#include "video.h"

extern void *sbrk(long);

void video_rewind(VIDWORK *work)
{
	work->src = (long)work->vid->src;
	work->pkn = 0;
	work->idx = 0;
	work->cnt = 0;
	work->frame = 0;
	work->timer = 0;
}

void video_init(VIDWORK *work, VIDEO *vid)
{
	unsigned int size;
	work->vid = vid;
	size = 2*vid->buf;
	work->buf = sbrk(size);
	size = 2*vid->wd*vid->ht;
	work->dst[0] = sbrk(size);
	work->dst[1] = sbrk(size);
	video_rewind(work);
}

void *video_proc(VIDWORK *work)
{
	unsigned int size;
	short *frame, *src, *dst, *end;
	int pki, pkn, idx, bit, cnt;
	OSIoMesg mb;
	OSMesgQueue mq;
	OSMesg mbox[1];
	osCreateMesgQueue(&mq, mbox, 1);
	size = 2*work->vid->buf;
	src = work->buf;
	osPiStartDma(&mb, OS_MESG_PRI_HIGH, OS_READ, work->src, src, size, &mq);
	osInvalDCache(src, size);
	osRecvMesg(&mq, NULL, OS_MESG_BLOCK);
	dst = frame = work->dst[work->frame & 1];
	end = dst + work->vid->wd*work->vid->ht;
	pki = work->pki;
	pkn = work->pkn;
	idx = work->idx;
	bit = work->bit << 16;
	cnt = work->cnt;
	for (;;)
	{
		while (pkn > 0)
		{
			if (dst == end) break;
			*dst++ = work->win[idx++ & 0xFFF] = work->win[pki++ & 0xFFF];
			pkn--;
		}
		if (dst == end) break;
		if (cnt == 0)
		{
			cnt = 16;
			bit = *src++ << 16;
		}
		if (bit < 0)
		{
			*dst++ = work->win[idx++ & 0xFFF] = *src++;
		}
		else
		{
			unsigned short x = *src++;
			pki = idx - ((x & 0xFFF)+1);
			pkn = (x >> 12) + 3;
		}
		bit <<= 1;
		cnt--;
	}
	work->src += (char *)src - (char *)work->buf;
	work->pki = pki;
	work->pkn = pkn;
	work->idx = idx;
	work->bit = bit >> 16;
	work->cnt = cnt;
	if (++work->frame >= work->vid->frame) video_rewind(work);
	return frame;
}
