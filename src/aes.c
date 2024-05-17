#include <ultra64.h>
#include <string.h>
#include "aes.h"

#define Nk 8
#define Nr 14

#define ROL(x, n) ((x) << (n) | (x) >> (8-(n)))

extern char sbox[256];
extern char rsbox[256];
extern char Rcon[10];

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

static void Sub4(char *data)
{
	int i;
	for (i = 0; i < 4; i++) data[i] = sbox[(unsigned char)data[i]];
}

static void RSub16(char *data)
{
	int i;
	for (i = 0; i < 16; i++) data[i] = rsbox[(unsigned char)data[i]];
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

void aes_init(void)
{
	int i, p, q, r;
	for (p = q = 1;;)
	{
		p ^= xtime(p);
		q ^= q << 1;
		q ^= q << 2;
		q ^= q << 4;
		if (q & 0x80) q ^= 0x09;
		q &= 0xFF;
		r = q ^ ROL(q, 1) ^ ROL(q, 2) ^ ROL(q, 3) ^ ROL(q, 4) ^ 0x63;
		r &= 0xFF;
		sbox[p] = r;
		rsbox[r] = p;
		if (p == 1) break;
	}
	sbox[0] = 0x63;
	for (i = 0; i < 8; i++) Rcon[i] = 1 << i;
	Rcon[8] = 0x1B;
	Rcon[9] = 0x36;
}

void aes_set_key(AESWORK *work, const void *key)
{
	int i, n;
	memcpy(work->key, key, 4*Nk);
	for (i = Nk; i < 4*(Nr+1); i++)
	{
		char k[4];
		for (n = 0; n < 4; n++) k[n] = work->key[4*(i-1)+n];
		if (i % 4 == 0) Sub4(k);
		if (i % Nk == 0)
		{
			unsigned char a = k[1] ^ Rcon[i/Nk-1];
			unsigned char b = k[2];
			unsigned char c = k[3];
			unsigned char d = k[0];
			k[0] = a;
			k[1] = b;
			k[2] = c;
			k[3] = d;
		}
		for (n = 0; n < 4; n++)
		{
			work->key[4*i+n] = work->key[4*(i-Nk)+n] ^ k[n];
		}
	}
}

void aes_cbc_decrypt(AESWORK *work, void *data, size_t size)
{
	int i;
	char *p;
	for (p = data; size > 0; p += 16, size -= 16)
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
