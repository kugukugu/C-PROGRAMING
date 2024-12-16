#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
	char infilename[100], infilename1[100], outfilename[100];

	FILE* fp, *fp1, *fpout;

	int i,j;

	printf("Input file name 1: ");
	scanf("%s%*c", infilename);
	printf("Input file name 2: ");
	scanf("%s%*c", infilename1);
	printf("Out file name: ");
	scanf("%s%*c", outfilename);

	fp = fopen(infilename, "rb");
	if(fp == NULL)
	{
		printf("(1) 읽기파일 열기 실패");
		return 1;
	}

	fp1 = fopen(infilename1, "rb");
	if (fp1 == NULL)
	{
		printf("(2) 읽기파일 열기 실패");
		return 1;
	}

	fpout = fopen(outfilename, "wb");
	if(fpout == NULL)
	{
		printf("쓰기파일 열기 실패");
		return 1;
	}

	char magic[3]; int width, height, channel = 1;
	char magic1[3]; int width1, height1;
	fscanf(fp, "%s%d%d", magic, &width, &height);
	fscanf(fp1, "%s%d%d", magic1, &width1, &height1);

	if (strcmp("P6", magic) == 0)
	{
		channel = 3;
	}

	printf("%s %d %d 255\n", magic, width , height);
	printf("%s %d %d 255\n", magic1, width1, height1);
	printf("%s %d %d 255\n", magic, width1+width, height);

	fprintf(fpout, "%s %d %d 255\n", magic, width +width1 , height);

	fseek(fp, -1 * width * channel * height, SEEK_END);
	fseek(fp1, -1 * width * channel * height, SEEK_END);

	unsigned char** buf = (unsigned char**)calloc(height, sizeof(unsigned char*));

	for ( i = 0; i < height; i++)
	{
		buf[i] = (unsigned char*)calloc(width * channel, sizeof(unsigned char));
	}

	for (i = 0; i < height; i++)
	{
		fread(buf[i], sizeof(unsigned char), width * channel, fp);
		fwrite(buf[i], sizeof(unsigned char), width * channel, fpout);

		fread(buf[i], sizeof(unsigned char), width * channel, fp1);
		fwrite(buf[i], sizeof(unsigned char), width * channel, fpout);
	}

	printf("성공");

	for (i = 0; i < height; i++)
	{
		free(buf[i]);
	}

	free(buf);

	fclose(fp);
	fclose(fp1);
	fclose(fpout);

	return 0;
}
