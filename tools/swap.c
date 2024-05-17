#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	size_t i, n, size;
	char *data;
	FILE *fp;
	if (argc != 3)
	{
		fprintf(stderr, "usage: %s <input> <output>\n", argv[0]);
		return 1;
	}
	if (!(fp = fopen(argv[1], "rb")))
	{
		fprintf(stderr, "error: could not read '%s'\n", argv[1]);
		return 1;
	}
	fseek(fp, 0, SEEK_END);
	data = calloc(n = ((size = ftell(fp))+3)/4, 4);
	fseek(fp, 0, SEEK_SET);
	for (i = 0; i < size; i++) data[i^3] = fgetc(fp);
	fclose(fp);
	if (!(fp = fopen(argv[2], "wb")))
	{
		fprintf(stderr, "error: could not write '%s'\n", argv[2]);
		return 1;
	}
	fwrite(data, 4, n, fp);
	fclose(fp);
	free(data);
	return 0;
}
