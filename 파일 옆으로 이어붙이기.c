#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	FILE* fpin, * fpin2, * fpout;

	char infilename[100], infilename2[100], outfilename[100];
	int i, j,k;

	printf("(1) 읽을 파일을 입력하시오. ");
	scanf("%s", infilename);

	printf("(2) 읽을 파일을 입력하시오. ");
	scanf("%s", infilename2);

	printf("쓸 파일을 입력하시오. ");
	scanf("%s", outfilename);

	fpin = fopen(infilename, "rb");
	if (fpin == NULL)
	{
		printf("읽을 파일 오픈 오류1\n");
		exit(1);
	}

	fpin2 = fopen(infilename2, "rb");
	if (fpin2 == NULL)
	{
		printf("읽을 파일 오픈 오류2\n");
		exit(1);
	}

	fpout = fopen(outfilename, "wb");
	if (fpout == NULL)
	{
		printf("쓰기 파일 오픈 오류\n");
		exit(1);
	}

	//P5 300 400 \n comment

	char magic[3]; int width, height, channel = 1;
	fscanf(fpin, "%s%d%d", magic, &width, &height); 

	if (strcmp("P6", magic) == 0)
	{
		channel = 3;
	}

	fprintf(fpout, "%s %d %d 255\n", magic, width*2, height);

	fseek(fpin, -width * height*channel, SEEK_END);
	fseek(fpin2, -width * height*channel, SEEK_END);

	char* p = (char*)malloc(sizeof(char) * width  * channel *2);

	/*for (i = 0; i < height; i++)
	{
		fread(p,sizeof(char), width * channel,fpin);
		fwrite(p, sizeof(char), width * channel, fpout);
		
		fread(p, sizeof(char), width * channel, fpin2);
		fwrite(p, sizeof(char), width  * channel, fpout);
	}*/

	for (j = 0; j < height; j++)
	{
		for (i = 0; i < width*channel; i++)
		{
			fread(&p[i], sizeof(char), 1, fpin);
		}

		for (k = width*channel; k < width * 2*channel; k++)
		{
			fread(&p[k], sizeof(char), 1, fpin2);
		}

		fwrite(p, sizeof(char), width * 2 * channel, fpout);
	}

	//for (j = 0; j < height; j++)
	//{
	//	// 첫 번째 이미지(snowman)에서 한 행 읽기
	//	fread(p, sizeof(char), width * channel, fpin);

	//	// 읽은 데이터를 출력 파일에 쓰기
	//	fwrite(p, sizeof(char), width * channel, fpout);

	//	// 두 번째 이미지(wintertree)에서 한 행 읽기
	//	fread(p + width * channel, sizeof(char), width * channel, fpin2);

	//	// 읽은 데이터를 출력 파일에 쓰기
	//	fwrite(p + width * channel, sizeof(char), width * channel, fpout);
	//}

	

	printf("The end of the show.");

	fclose(fpin);
	fclose(fpout);

	return 0;
}
