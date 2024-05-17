#include <ultra64.h>
#include <string.h>

extern s32 __osSiRawStartDma(s32, void *);
#define PIFRAMSIZE 16
typedef struct
{
	u32 ramarray[PIFRAMSIZE-1];
	u32 pifstatus;
}
OSPifRam;
#define CONT_SETCH              254
#define CONT_ETC                CONT_SETCH
extern OSPifRam __osContPifRam;
extern u8 __osContLastCmd;
extern void __osSiGetAccess(void);
extern void __osSiRelAccess(void);

s32 osCicScramble(OSMesgQueue *mq, void *buf)
{
	s32 ret = 0;
	int i;
	u8 *ptr = (u8 *)&__osContPifRam;
	__osSiGetAccess();
	for (i = 0; i < PIFRAMSIZE-1; i++) __osContPifRam.ramarray[i] = 0;
	__osContPifRam.pifstatus = 2;
	ptr[46] = 15;
	ptr[47] = 15;
	memcpy(ptr+48, buf, 15);
	if ((ret = __osSiRawStartDma(OS_WRITE, &__osContPifRam))) return ret;
	osRecvMesg(mq, NULL, OS_MESG_BLOCK);
	__osContLastCmd = CONT_ETC;
	if ((ret = __osSiRawStartDma(OS_READ, &__osContPifRam))) return ret;
	osRecvMesg(mq, NULL, OS_MESG_BLOCK);
	memcpy(buf, ptr+48, 15);
	__osSiRelAccess();
	return ret;
}
