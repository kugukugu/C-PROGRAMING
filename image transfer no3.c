#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE* fpin, * fpout;
	char ifilename[100], ofilename[100];
	printf("Type-in inputfilename: ");
	scanf("%s%*c", ifilename);

	printf("Type-in outputfilename: ");
	scanf("%s%*c", ofilename);

	char buffer[300], target[300];
	int i, j, k;

	fpin = fopen(ifilename, "rb");
	if (fpin == NULL)
	{
		printf("읽을 파일 오픈 오류\n");
		exit(1);
	}

	fpout = fopen(ofilename, "wb");
	if (fpout == NULL)
	{
		printf("쓰기 파일 오픈 오류\n");
		exit(1);
	}

	char magic[3]; int width, height; int channel = 1;
	fscanf(fpin, "%s%d%d", magic, &width, &height); //read header

	fprintf(fpout, "%s %d %d 255\n", magic, width, height);

	if (strcmp("P6", magic) == 0)
	{
		channel = 3;
	}

	char* ibuffer = (char*)malloc(width * channel);

	for (i = 1; i <= height; i++)
	{
		fseek(fpin, -1 * i * width * channel, SEEK_END); 
		fread(ibuffer, 1, width * channel, fpin);
		fwrite(ibuffer, 1, width * channel, fpout);
	}

	free(ibuffer);

	printf("The end of the show.");

	fclose(fpin);
	fclose(fpout);

	return 0;
}
