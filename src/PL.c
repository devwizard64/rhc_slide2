#include <ultra64.h>
#include <string.h>
#include "PL.h"

static u32 __PL_Request(u32 cmd, u32 *src, u32 *dst)
{
	int i;
	int n;
	unsigned int len;
	u32 status;
	if (src && (len = cmd & 0xFFFF))
	{
		n = (len+3) / 4;
		for (i = 0; i < n; i++) osPiWriteIo(0x1FFB0004 + 4*i, src[i]);
	}
	osPiWriteIo(0x1FFB0000, cmd);
	osPiReadIo(0x1FFB0000, &status);
	if (dst && (len = status & 0xFFFF))
	{
		n = (len+3) / 4;
		for (i = 0; i < n; i++) osPiReadIo(0x1FFB0004 + 4*i, &dst[i]);
	}
	return status;
}

static int __PL_GetVersion(PL_Version *version, u32 cmd)
{
	int result;
	unsigned int len;
	u32 status;
	u32 payload[2];
	status = __PL_Request(cmd, NULL, payload);
	result = status >> 16;
	if (!result)
	{
		len = status & 0xFFFF;
		memcpy(version, payload, len);
	}
	return result;
}

int PL_GetMagic(void)
{
	return __PL_Request(0x00000000, NULL, NULL) >> 16;
}

int PL_GetCoreVersion(PL_Version *version)
{
	return __PL_GetVersion(version, 0x00010000);
}

int PL_GetToken(u32 *token)
{
	return __PL_Request(0x00020000, NULL, token) >> 16;
}

int PL_GetCheatsUsed(void)
{
	return __PL_Request(0x00030000, NULL, NULL) >> 16;
}

int PL_GetGfxPlugin(PL_GfxPlugin *info)
{
	int result;
	unsigned int len;
	u32 status;
	u32 payload[4];
	status = __PL_Request(0x00040000, NULL, payload);
	result = status >> 16;
	if (!result)
	{
		len = status & 0xFFFF;
		memcpy(info, payload, len);
	}
	return result;
}

int PL_GetCheatFlags(void)
{
	return __PL_Request(0x00050000, NULL, NULL) >> 16;
}

int PL_ClrCheatsUsed(void)
{
	return __PL_Request(0x00060000, NULL, NULL) >> 16;
}

int PL_ClrCheatFlags(u8 flags)
{
	u32 payload[1];
	payload[0] = flags << 24;
	return __PL_Request(0x00060001, payload, NULL) >> 16;
}

int PL_GetLauncherVersion(PL_Version *version)
{
	return __PL_GetVersion(version, 0x01000000);
}

int PL_GetUsername(char *username)
{
	int result;
	unsigned int len;
	u32 status;
	u32 payload[8];
	status = __PL_Request(0x02000000, NULL, payload);
	result = status >> 16;
	len = status & 0xFFFF;
	if (!result)
	{
		memcpy(username, payload, len);
		username[len] = '\0';
	}
	return result;
}

int PL_GetAvatar(const char *username, void *avatar, int siz, int flag)
{
	int result;
	unsigned int len;
	u32 cmd;
	u32 status;
	u32 payload[8];
	len = strlen(username);
	memcpy(payload, username, len);
	cmd = 0x02000000 + ((siz-1) << 16) + len;
	status = __PL_Request(cmd, payload, avatar);
	if (flag)
	{
		while (status >> 24 == PL_EAGAIN)
		{
			status = __PL_Request(cmd, NULL, avatar);
		}
	}
	result = status >> 16;
	return result;
}

int PL_CheckAbi(int abi)
{
	PL_Version version;
	switch (abi)
	{
	case 1:
		return TRUE;
	case 2:
		if (PL_GetCoreVersion(&version)) return FALSE;
		if (version.major < 2 || version.minor < 13) return FALSE;
		return TRUE;
	case 3:
		if (PL_GetCoreVersion(&version)) return FALSE;
		if (version.major < 2 || version.minor < 13) return FALSE;
		if (PL_GetLauncherVersion(&version)) return FALSE;
		if (version.major < 6 || version.minor < 20) return FALSE;
		return TRUE;
	}
	return FALSE;
}
