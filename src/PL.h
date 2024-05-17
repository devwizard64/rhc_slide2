#ifndef __PL_H__
#define __PL_H__

#define PL_OK                   0
#define PL_ENOTSUP              1
#define PL_ESIZE                2
#define PL_EPIPE                3
#define PL_ENOTRECOVERABLE      4
#define PL_EAGAIN               5
#define PL_EINVAL               6

#define PL_PARALLEL             1
#define PL_GLIDEN64             2
#define PL_OGRE                 3
#define PL_GLIDE64              4
#define PL_ANGRYLIONS           5
#define PL_RICES                6
#define PL_GLN64                7

#define PL_UPSCALING            0x0001
#define PL_FBE                  0x0002
#define PL_ZCMP                 0x0004

#define PL_GAMESHARK            0x01
#define PL_SAVESTATE            0x02
#define PL_SLOWDOWN             0x04
#define PL_FRAMEADVANCE         0x08
#define PL_SPEEDUP              0x10
#define PL_ALLCHEAT             0xFF
#define PL_RTACHEAT             0xFE
#define PL_TASCHEAT             0x01

typedef struct PL_Version_s
{
	u16 major;
	u16 minor;
	u16 patch;
}
PL_Version;

typedef struct PL_GfxPlugin_s
{
	u16 code;
	u16 flag;
	char name[12];
}
PL_GfxPlugin;

extern int PL_GetMagic(void);
extern int PL_GetCoreVersion(PL_Version *version);
extern int PL_GetToken(u32 *token);
extern int PL_GetCheatsUsed(void);
extern int PL_GetGfxPlugin(PL_GfxPlugin *info);
extern int PL_GetCheatFlags(void);
extern int PL_ClrCheatsUsed(void);
extern int PL_ClrCheatFlags(u8 flags);
extern int PL_GetLauncherVersion(PL_Version *version);
extern int PL_GetUsername(char *username);
extern int PL_GetAvatar(const char *username, void *avatar, int siz, int flag);
extern int PL_CheckAbi(int abi);

#endif /* __PL_H__ */
