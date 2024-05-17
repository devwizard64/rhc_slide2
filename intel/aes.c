#include <string.h>
#include "aes.h"

#define Nk 8
#define Nr 14

extern char rsbox[256];
extern volatile int execstat;

static void Xor(char *data, const char *key, int index)
{
	int i;
	for (i = 0; i < 16; i++) data[i] ^= key[index+i];
}

static void RShiftRows(char *data)
{
	int i, n;
	char buf[16];
	for (i = 0; i < 4; i++)
	{
		for (n = 0; n < 4; n++) buf[4*i+n] = data[4*((i-n)&3)+n];
	}
	memcpy(data, buf, 16);
}

static void RSub16(char *data)
{
	int i;
	for (i = 0; i < 16; i++) data[i] = rsbox[(unsigned char)data[i]^3];
}

static unsigned char xtime(unsigned char x)
{
	unsigned char y = x << 1;
	if (x & 0x80) y ^= 0x1B;
	return y;
}

static unsigned char Mult(unsigned char a, unsigned char b)
{
	int i;
	unsigned char y = 0;
	for (i = 0; i < 3; i++)
	{
		if (b & 1) y ^= a;
		a = xtime(a);
		b >>= 1;
	}
	return y ^ a;
}

static void RMixColumns(char *data)
{
	int i;
	for (i = 0; i < 4; i++)
	{ 
		unsigned char a = data[4*i+0];
		unsigned char b = data[4*i+1];
		unsigned char c = data[4*i+2];
		unsigned char d = data[4*i+3];
		data[4*i+0] = Mult(a, 6) ^ Mult(b, 3) ^ Mult(c, 5) ^ Mult(d, 1);
		data[4*i+1] = Mult(a, 1) ^ Mult(b, 6) ^ Mult(c, 3) ^ Mult(d, 5);
		data[4*i+2] = Mult(a, 5) ^ Mult(b, 1) ^ Mult(c, 6) ^ Mult(d, 3);
		data[4*i+3] = Mult(a, 3) ^ Mult(b, 5) ^ Mult(c, 1) ^ Mult(d, 6);
	}
}

void aes_cbc_decrypt(AESWORK *work, void *data, size_t size)
{
	int i;
	char *p;
	for (p = data, size /= 16; size > 0; p += 16, execstat = --size)
	{
		char buf[16];
		memcpy(buf, p, 16);
		Xor(p, work->key, 16*Nr);
		for (i = Nr-1;; i--)
		{
			RShiftRows(p);
			RSub16(p);
			Xor(p, work->key, 16*i);
			if (i == 0) break;
			RMixColumns(p);
		}
		Xor(p, work->iv, 0);
		memcpy(work->iv, buf, 16);
	}
}
