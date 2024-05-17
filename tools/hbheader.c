#include <stdio.h>
#include <string.h>

static int saveopt(char *arg)
{
	if (!strcmp(arg, "eep4k"))      return 0x10;
	if (!strcmp(arg, "eep16k"))     return 0x20;
	if (!strcmp(arg, "sram256k"))   return 0x30;
	if (!strcmp(arg, "sram768k"))   return 0x40;
	if (!strcmp(arg, "flash"))      return 0x50;
	if (!strcmp(arg, "sram1m"))     return 0x60;
	return -1;
}

static int portopt(char *arg)
{
	if (!strcmp(arg, "null"))   return 0xFF;
	if (!strcmp(arg, "rpak"))   return 0x01;
	if (!strcmp(arg, "cpak"))   return 0x02;
	if (!strcmp(arg, "tpak"))   return 0x03;
	if (!strcmp(arg, "mouse"))  return 0x80;
	if (!strcmp(arg, "vru"))    return 0x81;
	if (!strcmp(arg, "gc"))     return 0x82;
	if (!strcmp(arg, "kb"))     return 0x83;
	if (!strcmp(arg, "gckb"))   return 0x84;
	return -1;
}

int main(int argc, char *argv[])
{
	int i;
	FILE *fp;
	const char *path = NULL;
	char port[4] = {0};
	char flag = 0;
	if (argc < 2)
	{
		fprintf(stderr, "usage: %s [options] romfile\n", argv[0]);
		fprintf(stderr,
			"\t-eep4k   \tEEPROM\t512 B\n"
			"\t-eep16k  \tEEPROM\t2048 B\n"
			"\t-sram256k\tSRAM  \t32 KiB\n"
			"\t-sram768K\tSRAM  \t96 KiB\n"
			"\t-flash   \tFlash \t128 KiB\n"
			"\t-sram1m  \tSRAM  \t128 KiB\n"
			"\t-p[1-4]\n"
			"\t    null \tPort unplugged\n"
			"\t    rpak \tController with Rumble Pak\n"
			"\t    cpak \tController with Controller Pak (memory)\n"
			"\t    tpak \tController with Transfer Pak\n"
			"\t    mouse\tN64 Mouse\n"
			"\t    vru  \tVoice Recognition Unit\n"
			"\t    gc   \tGameCube controller\n"
			"\t    kb   \tRandnet DD keyboard\n"
			"\t    gckb \tGameCube ASCII keyboard controller\n"
		);
		return 1;
	}
	for (i = 1; i < argc;)
	{
		int code;
		char *arg = argv[i++];
		if (arg[0] == '-')
		{
			arg++;
			if ((code = saveopt(arg)) >= 0)
			{
				flag = (flag & 3) | code;
			}
			else if (!strcmp(arg, "rtc"))
			{
				flag |= 1;
			}
			else if (!strcmp(arg, "regionfree"))
			{
				flag |= 2;
			}
			else if (arg[0] == 'p' && arg[1] >= '1' && arg[1] <= '4')
			{
				int p = arg[1]-'1';
				if (arg[2] != '\0')
				{
					arg = arg+2;
				}
				else if (i < argc)
				{
					arg = argv[i++];
				}
				else
				{
					fprintf(stderr, "error: malformed option\n");
					return 1;
				}
				if ((code = portopt(arg)) < 0)
				{
					fprintf(stderr, "error: unknown port option '%s'\n", arg);
				}
				port[p] = code;
			}
			else
			{
				fprintf(stderr, "error: unknown option '%s'\n", arg);
				return 1;
			}
		}
		else
		{
			if (!path)
			{
				path = arg;
			}
			else
			{
				fprintf(stderr, "error: multiple files specified\n");
				return 1;
			}
		}
	}
	if (!path)
	{
		fprintf(stderr, "error: no file specified\n");
		return 1;
	}
	if (!(fp = fopen(path, "r+b")))
	{
		fprintf(stderr, "error: could not open '%s'\n", path);
		return 1;
	}
	fseek(fp, 0x34, SEEK_SET);
	fwrite(port, 1, 4, fp);
	fseek(fp, 0x3C, SEEK_SET);
	fputc('E', fp);
	fputc('D', fp);
	fseek(fp, 0x3F, SEEK_SET);
	fputc(flag, fp);
	fclose(fp);
	return 0;
}
