#ifndef __AES_H__
#define __AES_H__

typedef struct aeswork
{
	char key[240];
	char iv[16];
}
AESWORK;

extern void aes_cbc_decrypt(AESWORK *work, void *data, size_t size);

#endif /* __AES_H__ */
