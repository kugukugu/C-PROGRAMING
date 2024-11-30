#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    // 다항식의 정보를 입력받아 저장한다. (모두 자연수로 가정)
      
    int N, coe[100] = { 0 }, degree[100] = { 0 }, x, sum=0;
    printf("항의 개수를 입력하시오.");                                        // -항의 개수 N
    scanf("%d", &N);
    int i,j;

    printf("각 항의 계수를 입력하시오.\n");
    for (i = 0; i < N; i++)                                                  // - 각 항의 계수 coeffcients
    {
        printf("%d번 째 항",i+1);
        scanf("%d", &coe[i]);
    }

    printf("각 항의 차수를 입력하시오.\n");
    for (i = 0; i < N; i++)
    {
        printf("%d번 째 항", i + 1);                                        //  - 각항의 차수 degree
        scanf("%d", &degree[i]);
    }

    int* p;
    
    printf("미지수 x를 입력하시오.");                                   //   미지수 X를 입력받아 다항식의 값을 계산하여 출력한다.
    scanf("%d", &x);

    p = (int*)malloc(sizeof(int) * N);

    for (i = 0; i < N; i++)
    {
        p[i] = coe[i];
        for (j = 0; j < degree[i]; j++)
        {
            p[i] = p[i] * x;
        }
        sum += p[i];
    }
   
    printf("sum = %d", sum);

    free(p);

	return 0;
}
