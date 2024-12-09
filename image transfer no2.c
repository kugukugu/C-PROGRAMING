#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	FILE* finput, *finput1, * foutput;
	char ifilename[100], ifilename1[100], ofilename[100] ;


	printf("첫 번째 읽을 파일을 입력하시오. ");
	scanf("%s%*c", ifilename);

	printf("두 번째 읽을 파일을 입력하시오. ");
	scanf("%s%*c", ifilename1);

	printf("쓸 파일을 입력하시오. ");
	scanf("%s%*c", ofilename);

	
	finput = fopen(ifilename, "rb");
	if (finput == NULL)
	{
		printf("읽을 파일 읽기 오류");
		return 1;
	}

	finput1 = fopen(ifilename1, "rb");
	if (finput == NULL)
	{
		printf("읽을 파일 읽기 오류");
		return 1;
	}

	foutput = fopen(ofilename, "wb");
	if(foutput == NULL)
	{
		printf("쓸 파일 읽기 오류");
		return 1;
	}

	char magic[3],magic1[3]; int width, width1, height,height1, channel=1;

	fscanf(finput, "%s%d%d", magic, &width, &height);
	fscanf(finput1, "%s%d%d", magic1, &width1, &height1);

	if (strcmp("P6", magic) == 0)
	{
		channel = 3;
	}

	fprintf(foutput, "%s %d %d 255\n", magic, width, height+height1);

	fseek(finput, -1 * width * height*channel, SEEK_END);
	fseek(finput1, -1 * width1 * height1 * channel, SEEK_END);

	char** p;
	p = (char**)malloc(height * sizeof(char*));

	int i;

	for (i = 0; i < height; i++)
	{
		p[i] = (char*)malloc(sizeof(char) * width * channel);
		fread(p[i], sizeof(char), width * channel, finput);
		fwrite(p[i], sizeof(char), width * channel, foutput);
	}

	for (i = height; i < height+height1; i++)
	{
		p[i] = (char*)malloc(sizeof(char) * width*channel);
		fread(p[i], sizeof(char), width1 * channel, finput1);
		fwrite(p[i], sizeof(char), width1 * channel, foutput);
	}

	printf("파일 닫기\n");

	/*for (i = 0; i < height + height1; i++)
	{
		free(p[i]);
	}

	free(p);*/

	fclose(finput);
	fclose(finput1);
	fclose(foutput);

	return 0;
}
