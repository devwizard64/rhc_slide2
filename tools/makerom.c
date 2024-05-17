#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>

#include "elf.h"
#include "elf.c"

#define CBC 1
#define ECB 0
#define CTR 0
#define AES256 1
#include "aes.h"
#include "aes.c"

#define HI(x)   (((x) >> 16) + ((x) >> 15 & 1))
#define LO(x)   ((x) & 0xFFFF)

static uint32_t c0, c1;

static void makeheader(unsigned char *data, const char *path)
{
	int i;
	FILE *fp;
	if (!(fp = fopen(path, "r")))
	{
		fprintf(stderr, "error: could not read '%s'\n", path);
		exit(1);
	}
	for (i = 0; i < 32;)
	{
		int c = getc(fp);
		if (c < 0) break;
		else if (c >= '0' && c <= '9') c -= '0'- 0;
		else if (c >= 'A' && c <= 'F') c -= 'A'-10;
		else if (c >= 'a' && c <= 'f') c -= 'a'-10;
		else continue;
		if (!(i & 1))   data[i >> 1] = c << 4;
		else            data[i >> 1] |= c;
		i++;
	}
	fclose(fp);
}

static void makecrt0(unsigned char *data, ELF *elf)
{
	int i;
	uint32_t *p = (uint32_t *)data;
	uint32_t entry = 0;
	uint32_t stack = 0;
	uint32_t bssStart = 0;
	uint32_t bssEnd = 0;
	uint32_t bssSize;
	for (i = 0; i < elf->symnum; i++)
	{
		const char *name = elf_stname(elf, &elf->symtab[i]);
		uint32_t value = ntohl(elf->symtab[i].value);
		if (!entry    && !strcmp(name, "__crt0Entry"))      entry    = value;
		if (!stack    && !strcmp(name, "__crt0Stack"))      stack    = value;
		if (!bssStart && !strcmp(name, "__crt0BssStart"))   bssStart = value;
		if (!bssEnd   && !strcmp(name, "__crt0BssEnd"))     bssEnd   = value;
		if (entry && stack && bssStart && bssEnd) break;
	}
	if ((bssSize = bssEnd-bssStart) > 0)
	{
		uint16_t bssSizeHi = bssSize >> 16;
		uint16_t bssSizeLo = bssSize;
		if      (bssStart)  *p++ = htonl(0x3C080000 | HI(bssStart));
		if      (bssSizeHi) *p++ = htonl(0x3C090000 | bssSizeHi);
		if      (bssStart)  *p++ = htonl(0x25080000 | LO(bssStart));
		if      (bssSizeHi) *p++ = htonl(0x35290000 | bssSizeLo);
		else if (bssSize > 0x7FFF)  *p++ = htonl(0x34090000 | bssSize);
		else                        *p++ = htonl(0x24090000 | bssSize);
		*p++ = htonl(0x2129FFF8);
		*p++ = htonl(0xAD000000);
		*p++ = htonl(0xAD000004);
		*p++ = htonl(0x1520FFFC);
		*p++ = htonl(0x21080008);
	}
	if      (entry) *p++ = htonl(0x3C0A0000 | HI(entry));
	if      (stack) *p++ = htonl(0x3C1D0000 | HI(stack));
	if      (entry) *p++ = htonl(0x254A0000 | LO(entry));
	if      (entry) *p++ = htonl(0x01400008);
	if      (stack) *p++ = htonl(0x27BD0000 | LO(stack));
	else if (entry) *p++ = htonl(0x00000000);
}

static void calc3(unsigned char *data, size_t size)
{
	size_t i;
	uint64_t v0 = 0xF8CA4DDCF8CA4DDC;
	uint32_t v1 = 0xF8CA4DDC;
	uint32_t v2 = 0xF8CA4DDC;
	uint32_t v3 = 0xF8CA4DDC;
	uint32_t v4 = 0xF8CA4DDC;
	for (i = 0x1000; i < 0x101000 && i < size; i += 4)
	{
		uint32_t x =
			data[i+0] << 24 | data[i+1] << 16 | data[i+2] << 8 | data[i+3];
		uint32_t y = x << (x & 31) | x >> (-x & 31);
		v0 += x;
		v1 ^= x;
		v2 += y;
		v3 ^= v3 < x ? (uint32_t)v0^x : y;
		v4 += v2^x;
	}
	for (; i < 0x101000; i += 4) v4 += v2;
	c0 = (uint32_t)(v0 >> 32) ^ (uint32_t)v0 ^ v1;
	c1 = v2 ^ v3 ^ v4;
	data[0x10] = c0 >> 24;
	data[0x11] = c0 >> 16;
	data[0x12] = c0 >>  8;
	data[0x13] = c0 >>  0;
	data[0x14] = c1 >> 24;
	data[0x15] = c1 >> 16;
	data[0x16] = c1 >>  8;
	data[0x17] = c1 >>  0;
}

static void scramble(char *dst, const char *src)
{
	int i;
	int w = 0;
	int z = 11;
	for (i = 0; i < 30; i++)
	{
		int s = 4*(~i&1);
		int x = src[i>>1] >> s & 15;
		int y = (z + 5*x) & 15;
		dst[i>>1] &= ~(15 << s);
		dst[i>>1] |= y << s;
		z = (w ? 0x9C36589C1E5E7A14 : 0x9636F8FC1E5E7A74) >> (4*y) & 15;
		w = (w ? 0x036F : 0x496D) >> y & 1;
	}
}

static void byteswap(unsigned char *data, size_t size)
{
	size_t i;
	for (i = 0; i < size; i += 4)
	{
		unsigned char a = data[i+0];
		unsigned char b = data[i+1];
		unsigned char c = data[i+2];
		unsigned char d = data[i+3];
		data[i+0] = d;
		data[i+1] = c;
		data[i+2] = b;
		data[i+3] = a;
	}
}

static void encrypt(unsigned char *data, ELF *elf)
{
	int i, sum;
	FILE *fp;
	struct AES_ctx ctx;
	char key[32];
	char iv[16];
	uint32_t v[4];
	uint32_t eStart = 0;
	uint32_t eEnd = 0;
	uint32_t dStart = 0;
	uint32_t dEnd = 0;
	for (i = 0; i < elf->symnum; i++)
	{
		const char *name = elf_stname(elf, &elf->symtab[i]);
		uint32_t value = ntohl(elf->symtab[i].value);
		if (!eStart && !strcmp(name, "_execSegmentRomStart"))    eStart = value;
		if (!eEnd   && !strcmp(name, "_execSegmentRomEnd"))      eEnd   = value;
		if (!dStart && !strcmp(name, "_dolphinSegmentRomStart")) dStart = value;
		if (!dEnd   && !strcmp(name, "_dolphinSegmentRomEnd"))   dEnd   = value;
		if (eStart && eEnd && dStart && dEnd) break;
	}
	sum = 0;
	for (i = 0; i < (int)(eEnd-eStart); i += 4)
	{
		unsigned char *p = data + eStart + i;
		sum -= (int32_t)(p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3]);
	}
	data[eStart+4] = sum >> 24;
	data[eStart+5] = sum >> 16;
	data[eStart+6] = sum >>  8;
	data[eStart+7] = sum >>  0;
	if (!(fp = fopen("ext/key.bin", "rb")))
	{
		fprintf(stderr, "error: could not read '%s'\n", "ext/key.bin");
		exit(1);
	}
	fread(key, 32, 1, fp);
	fclose(fp);
	v[0] = -c1;
	v[1] =  c0;
	v[2] =  c1;
	v[3] = ~c0;
	for (i = 0; i < 16; i++) iv[i] = v[i>>2] >> (8*(~i&3));
	scramble(iv, iv);
	AES_init_ctx_iv(&ctx, (uint8_t *)key, (uint8_t *)iv);
	AES_CBC_encrypt_buffer(&ctx, data+eStart, eEnd-eStart);
	byteswap((unsigned char *)&ctx, sizeof(struct AES_ctx));
	byteswap(data+dStart, 16);
	AES_CBC_encrypt_buffer(&ctx, data+dStart, dEnd-dStart);
	byteswap(data+dStart, dEnd-dStart);
}

static void usage(const char *path)
{
	fprintf(stderr, "usage: %s [options] elffile\n", path);
	fprintf(stderr,
		"\t-r romfile\n"
		"\t-h headerfile\n"
		"\t-b bootfile\n"
		"\t-F fontfile\n"
		"\t-s romsize (Mbits)\n"
		"\t-a align\n"
		"\t-f filldata (0x00 - 0xff)\n"
	);
}

int main(int argc, char *argv[])
{
	int c;
	FILE *fp;
	unsigned char *data;
	size_t size;
	size_t end;
	size_t align;
	ELF elf;
	const char *opt_rom = "rom";
	const char *opt_header = "header";
	const char *opt_boot = "Boot";
	const char *opt_font = "font";
	long opt_size = 0;
	long opt_align = 0;
	long opt_fill = 0;
	while ((c = getopt(argc, argv, "r:h:b:F:s:a:f:")) != -1)
	{
		switch (c)
		{
		case 'r':
			opt_rom = optarg;
			break;
		case 'h':
			opt_header = optarg;
			break;
		case 'b':
			opt_boot = optarg;
			break;
		case 'F':
			opt_font = optarg;
			break;
		case 's':
			opt_size = strtol(optarg, NULL, 0);
			break;
		case 'a':
			opt_align = strtol(optarg, NULL, 0);
			break;
		case 'f':
			opt_fill = strtol(optarg, NULL, 0);
			break;
		case '?':
			usage(argv[0]);
			return 1;
			break;
		}
	}
	if (argc-optind != 1)
	{
		usage(argv[0]);
		return 1;
	}
	elf_open(&elf, argv[optind], "rb");
	elf_loadsection(&elf);
	end = 0x1000 + elf_size(&elf);
	size = 1024*1024/8 * opt_size;
	if (size < end) size = end;
	align = (1 << opt_align) - 1;
	size = (size+align) & ~align;
	memset(data = malloc(size), 0, end);
	makeheader(data, opt_header);
	if (!(fp = fopen(opt_boot, "rb")))
	{
		fprintf(stderr, "error: could not read '%s'\n", opt_boot);
		return 1;
	}
	fread(&data[0x40], 1, 0xB70-0x40, fp);
	fclose(fp);
	if (!(fp = fopen(opt_font, "rb")))
	{
		fprintf(stderr, "error: could not read '%s'\n", opt_font);
		return 1;
	}
	fread(&data[0xB70], 1, 0x1000-0xB70, fp);
	fclose(fp);
	elf_load(&elf, data+0x1000);
	makecrt0(data+0x1000, &elf);
	*(uint32_t *)(data+8) = elf.eh.entry;
	memset(data+end, opt_fill, size-end);
	calc3(data, size);
	if (!(fp = fopen("/dev/urandom", "rb")))
	{
		fprintf(stderr, "error: could not read '%s'\n", "/dev/urandom");
		return 1;
	}
	fread(data+end, 1, size-end, fp);
	fclose(fp);
	encrypt(data, &elf);
	elf_close(&elf);
	if (!(fp = fopen(opt_rom, "wb")))
	{
		fprintf(stderr, "error: could not write '%s'\n", opt_rom);
		return 1;
	}
	fwrite(data, 1, size, fp);
	fclose(fp);
	free(data);
	return 0;
}
