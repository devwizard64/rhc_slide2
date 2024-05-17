#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "elf.h"
#include "elf.c"

#define BLK_OL  1
#define BLK_SL  3
#define BLK_OH  (BLK_OL+0xFFF)
#define BLK_SM  (BLK_SL+0xF)
#define BLK_SH  (BLK_SM+0xFF)
#define BITCNT 8
#define slitbl() \
{ \
	*(t = s++) = 0; \
}
#define slipkt() \
{ \
	*p++ = x >> 8; \
	*p++ = x >> 0; \
	if (sz >= BLK_SM) *c++ = sz-BLK_SM; \
	else p[-2] |= (sz-(BLK_SL-1)) << 4; \
}
#define slicpy() \
{ \
	*c++ = data[i++]; \
	*t |= 0x80 >> cnt; \
}
#define slicnt() \
{ \
	cnt = (cnt+1) & (BITCNT-1); \
}

static int sliblk(const char *data, size_t size, size_t i, int *of, int *sz)
{
	int flag = 0;
	size_t o = i < BLK_OH ? 0 : i-BLK_OH;
	int c = size-i < BLK_SH ? size-i : BLK_SH;
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

static size_t slielf(ELF *elf, const char *data, size_t size)
{
	int i;
	uint32_t end = 0;
	for (i = 0; i < elf->symnum; i++)
	{
		uint32_t value = ntohl(elf->symtab[i].value);
		uint32_t size = ntohl(elf->symtab[i].size);
		if (end < value+size) end = value+size;
		if (ST_BIND(elf->symtab[i].info) != STB_LOCAL)
		{
			const char *name = elf_stname(elf, &elf->symtab[i]);
			printf(".globl %s; %s = 0x%08X\n", name, name, value);
		}
	}
	end &= 0xFFFFFF;
	if (size-end >= 16) return size;
	for (i = 0; i < (int)(size-end); i++)
	{
		if (data[end+i]) return size;
	}
	return end;
}

int main(int argc, char *argv[])
{
	FILE *fp;
	char *data;
	size_t size;
	size_t i;
	size_t cnt;
	char *stm;
	char *s;
	char *t;
	if (argc != 3)
	{
		fprintf(stderr, "usage: %s <input> <szs>\n", argv[0]);
		return 1;
	}
	if (!strcmp(argv[1]+strlen(argv[1])-4, ".elf"))
	{
		ELF elf;
		elf_open(&elf, argv[1], "rb");
		elf_loadsection(&elf);
		elf_load(&elf, data = malloc(size = elf_size(&elf)));
		size = slielf(&elf, data, size);
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
	s = stm = malloc(size + size/4);
#define p s
#define c s
	i = 0;
	cnt = 0;
	while (i < size)
	{
		int of;
		int sz;
		if (sz = BLK_SL-1, sliblk(data, size, i, &of, &sz))
		{
			int x;
			int ofn;
			int szn;
			if (szn = sz+1, sliblk(data, size, i+1, &ofn, &szn))
			{
				if (cnt == 0) slitbl();
				slicpy();
				slicnt();
				of = ofn;
				sz = szn;
			}
			x = i-of-BLK_OL;
			if (cnt == 0) slitbl();
			slipkt();
			slicnt();
			i += sz;
		}
		else
		{
			if (cnt == 0) slitbl();
			slicpy();
			slicnt();
		}
	}
	free(data);
	printf(".data\n.incbin \"%s\"\n", argv[2]);
	if (!(fp = fopen(argv[2], "wb")))
	{
		fprintf(stderr, "error: could not write '%s'\n", argv[2]);
		return 1;
	}
	fwrite("Yaz0", 1, 4, fp);
	fputc(size >> 24, fp);
	fputc(size >> 16, fp);
	fputc(size >>  8, fp);
	fputc(size >>  0, fp);
	fwrite("\0\0\0\0\0\0\0", 1, 8, fp);
	fwrite(stm, 1, s-stm, fp); free(stm);
	fclose(fp);
	return 0;
}
