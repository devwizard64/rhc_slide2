#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "elf.h"
#include "elf.c"

#define BLK_OL  1
#define BLK_SL  3
#define BLK_OH  (BLK_OL+0xFFF)
#define BLK_SH  (BLK_SL+0xF)
#define BITCNT 16
#define vidtbl() \
{ \
	*(t = s++) = 0; \
}
#define vidpkt() \
{ \
	*s++ = x << 8 | x >> 8 | (sz-BLK_SL) << 4; \
}
#define vidcpy() \
{ \
	*s++ = data[i++]; \
	*t |= 0x80 << (cnt & 8) >> (cnt&7); \
}
#define vidcnt() \
{ \
	cnt = (cnt+1) & (BITCNT-1); \
}

static int vidblk(const short *data, size_t len, size_t i, int *of, int *sz)
{
	int flag = 0;
	size_t o = i < BLK_OH ? 0 : i-BLK_OH;
	int c = len-i < BLK_SH ? len-i : BLK_SH;
	while (o < i && *sz < c)
	{
		int s = 0;
		int n = 0;
		while (o+s < i+c && s < c)
		{
			if (data[i+s] != data[o+s < i ? o+s : o+(s%n)]) break;
			if (o+s < i) n++;
			s++;
		}
		if (*sz < s)
		{
			*of = o;
			*sz = s;
			flag = 1;
		}
		o++;
	}
	return flag;
}

int main(int argc, char *argv[])
{
	FILE *fp;
	short *data;
	size_t size;
	size_t len;
	size_t i;
	size_t cnt;
	short *stm;
	short *s;
	short *t;
	if (argc != 3)
	{
		fprintf(stderr, "usage: %s <input> <vid>\n", argv[0]);
		return 1;
	}
	if (!strcmp(argv[1]+strlen(argv[1])-4, ".elf"))
	{
		ELF elf;
		elf_open(&elf, argv[1], "rb");
		elf_load(&elf, data = malloc(size = elf_size(&elf)));
		elf_close(&elf);
	}
	else
	{
		if (!(fp = fopen(argv[1], "rb")))
		{
			fprintf(stderr, "error: could not read '%s'\n", argv[1]);
			return 1;
		}
		fseek(fp, 0, SEEK_END);
		data = malloc(size = ftell(fp));
		fseek(fp, 0, SEEK_SET);
		fread(data, 1, size, fp);
		fclose(fp);
	}
	stm = s = malloc(size);
	len = size/2;
	i = 0;
	cnt = 0;
	while (i < len)
	{
		int of;
		int sz;
		if (sz = BLK_SL-1, vidblk(data, len, i, &of, &sz))
		{
			int ofn;
			int szn;
			int x;
			while (szn = sz+1, vidblk(data, len, i+1, &ofn, &szn))
			{
				if (cnt == 0) vidtbl();
				vidcpy();
				vidcnt();
				of = ofn;
				sz = szn;
			}
			x = i-of-BLK_OL;
			if (cnt == 0) vidtbl();
			vidpkt();
			vidcnt();
			i += sz;
		}
		else
		{
			if (cnt == 0) vidtbl();
			vidcpy();
			vidcnt();
		}
	}
	free(data);
	printf(".data\n.incbin \"%s\"\n", argv[2]);
	if (!(fp = fopen(argv[2], "wb")))
	{
		fprintf(stderr, "error: could not write '%s'\n", argv[2]);
		return 1;
	}
	fwrite(stm, 1, (char *)s - (char *)stm, fp); free(stm);
	fclose(fp);
	return 0;
}
