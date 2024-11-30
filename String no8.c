#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(char** a, char** b)
{
    return strcmp(*a, *b);
}

char dcompare(char* a, char* b)
{
    return *a - *b;
}

int main()
{
    int N, i;

    printf("문자열의 개수 N을 입력하시오. ");
    scanf("%d", &N);
    getchar();

    char** p;

    p = (char**)malloc(sizeof(char*) * N);

    for (i = 0; i < N; i++)
    {
        p[i] = malloc(sizeof(char) * 101);
        printf("%d번째 문자열을 입력하시오. ",i+1);
        gets(p[i]);
    }

    qsort(p, N, sizeof(char*), compare);

    for(i=0; i<N; i++)
    {
        printf("%s\n", p[i]);
    }

    printf("\n");
    
    for(i=0; i<N; i++)
    {
        qsort( *(p+i) ,strlen(p[i]),sizeof(char),dcompare);
        printf("%s\n", p[i]);
    }

    free(p);

    return 0;
}
