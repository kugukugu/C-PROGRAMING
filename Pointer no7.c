#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    srand(time(NULL));
    int N,M,cnt=0;

    printf(" N과 M을 입력하시오.");
    scanf("%d %d", &N,&M);

    int **p = (int**)malloc(N*sizeof(int *));
    int **q = (int**)malloc(M*sizeof(int *));
    int **r = (int**)malloc(N*sizeof(int *));

    int i,j,k ;

    for(i=0; i<N; i++)
    {
        *(p+i)=(int *)malloc(M*sizeof(int));
    }

    for(i=0; i<M; i++)
    {

        *(q+i)=(int *)malloc(N*sizeof(int));
    }

    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            //p[i][j]= rand() % 10 + 1;
            *(*(p+i)+j) = rand() % 10 + 1;
        }
    }

    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            //p[i][j]= rand() % 10 + 1;
            *(*(q+i)+j) = rand() % 10 + 1;
        }
    }

    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            printf("%d ", q[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    for(i=0; i<N; i++)
    {
        *(r+i) = (int *)malloc(N*sizeof(int));
    }

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < M; k++)
			{
			    r[i][j] = 0;
				r[i][j] += p[i][k] * q[k][j];
			}
		}
	}

  for(i=0; i<N; i++)
  {
      for(j=0; j<N; j++)
      {
          //printf("%d ", *(*(r+i)+j));
           printf("%d ", r[i][j]);
      }
        printf("\n");
  }

    return 0;
}
