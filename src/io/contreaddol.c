#include <ultra64.h>
#include <string.h>

#include "dolphin_pad.h"

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
#define CON_ERR_MASK            0xc0
#define CONT_FORMAT             1
#define FORMAT_END              0xfe
extern OSPifRam __osContPifRam;
extern u8 __osContLastCmd;
extern u8 __osMaxControllers;
extern void __osSiGetAccess(void);
extern void __osSiRelAccess(void);

static void __osPackReadDol(void);

s32 osContStartReadDol(OSMesgQueue *mq)
{
	s32 ret = 0;
	__osSiGetAccess();
	if (__osContLastCmd != 64)
	{
		__osPackReadDol();
		ret = __osSiRawStartDma(OS_WRITE, &__osContPifRam);
		osRecvMesg(mq, NULL, OS_MESG_BLOCK);
	}
	ret = __osSiRawStartDma(OS_READ, &__osContPifRam);
	__osContLastCmd = 64;
	__osSiRelAccess();
	return ret;
}

void osContGetReadDol(PADStatus *status)
{
	u8 *ptr = (u8 *)&__osContPifRam;
	int i;
	for (i = 0; i < __osMaxControllers; i++)
	{
		if      (ptr[1] & 0x80) status[i].err = PAD_ERR_NO_CONTROLLER;
		else if (ptr[1] & 0x40) status[i].err = PAD_ERR_TRANSFER;
		else                    status[i].err = PAD_ERR_NONE;
		if (status[i].err == PAD_ERR_NONE)
		{
			status[i].button = ptr[5] << 8 | ptr[6];
			status[i].stickX = ptr[7] - 128;
			status[i].stickY = ptr[8] - 128;
			status[i].substickX = ptr[9] - 128;
			status[i].substickY = ptr[10] - 128;
			status[i].triggerLeft = ptr[11];
			status[i].triggerRight = ptr[12];
			status[i].analogA = 0;
			status[i].analogB = 0;
		}
		ptr += 13;
	}
}

static void __osPackReadDol(void)
{
	u8 *ptr = (u8 *)&__osContPifRam;
	int i;
	for (i = 0; i < PIFRAMSIZE-1; i++) __osContPifRam.ramarray[i] = 0;
	__osContPifRam.pifstatus = CONT_FORMAT;
	for (i = 0; i < __osMaxControllers; i++)
	{
		ptr[0] = 3;
		ptr[1] = 8;
		ptr[2] = 64;
		ptr[3] = 3;
		ptr += 13;
	}
	*ptr = FORMAT_END;
}
