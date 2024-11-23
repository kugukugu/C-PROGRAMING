#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>

void menu();

int main()
{
    srand(time(NULL));
    int n, i=0, j=0, k=0;
    int m[30], p[30], c[10];

    menu();

    while(1)
    {
        scanf("%d", &n);

        if(n>= 1 && n<4)
        {
            break;
        }
        printf("다시 입력하세요. ");
    }





    switch(n)
    {
        case 1:
            m[i]= -1*(rand() % 29 + 1);
            while(1)
            {
                for(int g=0; g<i; g++)
                {
                    if(m[g]==m[i])
                    {
                        m[i]= -1*(rand() % 29 + 1); //이미 선택한 숫자가 나올 경우 재생성
                        break;
                    }
                }             
                
            }
                                        
            c[k++]= m[i];
            printf("%d\n", m[i++]);
            break;
        case 2:
           for(int k = 1; k<31; k++)
           {
               printf("%d ", k);
           }
           
            break;
//        case 3:


    }

    return 0;
}

void menu()
{
    printf("1. -1 ~ -30 랜덤 숫자 생성\n");
    printf("2.  1 ~  30 랜덤 숫자 생성\n");
    printf("3. 현재 선택된 숫자 출력 및 선택 해제\n");
}
