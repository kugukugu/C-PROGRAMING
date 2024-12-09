#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE* fpin, * fpin2, * fpout;
	char ifilename[100], ifilename2[100], ofilename[100];
	printf("Two input inputfilename: ");
	scanf("%s%s%*c", ifilename, ifilename2);

	printf("Type-in outputfilename: ");
	scanf("%s%*c", ofilename);

	char buffer[300], target[300];
	int i, j, k;

	fpin = fopen(ifilename, "rb");
	if (fpin == NULL)
	{
		printf("1. 읽을 파일 오픈 오류\n");
		exit(1);
	}

	fpin2 = fopen(ifilename2, "rb");
	if (fpin2 == NULL)
	{
		printf("2. 읽을 파일 오픈 오류\n");
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
	fscanf(fpin2, "%s%d%d", magic, &width, &height); //read header

	fprintf(fpout, "%s %d %d 255\n", magic, width, height*2);

	if (strcmp("P6", magic) == 0)
	{
		channel = 3;
	}

	fseek(fpin, -width * height* channel, SEEK_END);
	fseek(fpin2, -width * height * channel, SEEK_END);
	
	char* ibuffer = (char*)malloc(width * channel);

	for (i = 1; i <= height; i++)
	{
		fread(ibuffer, 1, width * channel, fpin);
		fwrite(ibuffer, 1, width * channel, fpout);
	}

	for (i = 1; i <= height; i++)
	{
		fread(ibuffer, 1, width * channel, fpin2);
		fwrite(ibuffer, 1, width * channel, fpout);
	}

	free(ibuffer);

	printf("The end of the show.");

	fclose(fpin);
	fclose(fpout);

	return 0;
}
