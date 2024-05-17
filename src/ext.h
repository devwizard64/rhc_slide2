#define ExtMoveWindow() extexec(1)
#define ExtColorKey() extexec(2)
#define ExtShowOBSError() extexec(3)
#define ExtExecDolphin() extexec(4)

extern int extinit(void);
extern void extmessage(void);
extern void extexec(int state);
extern int extproc(void);
