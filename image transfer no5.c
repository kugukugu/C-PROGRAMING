#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

unsigned char main(void)
{
	int i, j, garo, sero;
	printf("input sero garo: ");
	scanf("%d %d", &sero, &garo);

	unsigned char** p = (unsigned char**)malloc(sizeof(unsigned char*) * sero);

	for (i = 0; i < sero; i++)
	{
		p[i] = (unsigned char*)malloc(sizeof(unsigned char) * garo);
	}

	FILE* fp, *fpout;

	fp = fopen("snowman.pgm", "rb");
	if(fp == NULL)
	{
		printf("읽기파일 열기 실패");
		return 1;
	}

	fpout = fopen("copy.pgm", "wb");
	if(fpout == NULL)
	{
		printf("쓰기파일 열기 실패");
		return 1;
	}

	fprintf(fpout, "%s %d %d 255\n", "P5", garo, sero);
	fseek(fp, -1*garo*sero,SEEK_END);

	for (i = 0; i < sero; i++)
	{
		fread(p[i], sizeof(char), garo, fp);
	}


	printf("Mosaic range(x1 x2 y1 y2): ");
	int x1, x2, y1, y2;
	scanf("%d%d%d%d%*c", &x1, &x2, &y1, &y2);

	for (i = y1; i < y2; i++)
	{
		for (j = x1; j < x2; j++)
		{
			p[i][j] = (unsigned char)0;
		}
	}

	for (i = 0; i < sero; i++)
	{
		fwrite(p[i], sizeof(char), garo, fpout);
	}
	printf("성공");

	fclose(fp);
	fclose(fpout);

	return 0;
}
