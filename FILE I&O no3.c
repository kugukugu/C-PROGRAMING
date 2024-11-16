#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(void)
{
    FILE* file;
    int i, n, number, count =0, sum=0;
    double average;

    printf("저장할 숫자의 개수를 입력하세요: ");
    scanf("%d", &n);

    file = fopen("kim.txt", "wt");

    if (file == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    printf("숫자 %d개를 입력하세요:\n", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &number);
        fprintf(file,"%d ",number);
    }

    fclose(file);

    file = fopen("kim.txt", "rt");

    if (file == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    while( fscanf(file,"%d",&number) != -1)
    {
        sum += number;
        count +=1;
    }

    fclose(file);

    average = (float) sum / count ;


    printf("합계: %d\n", sum);
    printf("평균: %.2f\n", average);

	return 0;
}
