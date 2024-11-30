#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char compare(char* a, char* b)
{
	return (*a) - (*b);
}

int main()
{
	// qsort를 활용해 알파벳 순으로 정렬하여 출력한다.
	
	int N;
	char* p;

	printf("문자열 길이 N을 입력하시오. ");  //문자열 길이를 입력받는다.
	scanf("%d", &N); 

	p = (char*)malloc(sizeof(char) * N);

	printf("문자열을 입력하시오. ");               //메모리 공간을 확보하고 문자열을 받아 저장한다.
	scanf("%s", p);

	qsort(p, N - 1, sizeof(char), compare);

	printf("%s", p);

	free(p);

	return 0;
}
