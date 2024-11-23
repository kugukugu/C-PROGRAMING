#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
    srand(time(NULL));

    int a, g,i, N;

    FILE* file;

    file = fopen("hello.bin", "wb"); //파일을 쓰기 바이너리 모드로 열기

    if (!file)
    {
        printf("파일 열기 실패");
        return 1;
    }

    printf("정수를 입력하시오. "); //정수 하나를 입력받고 해당수만큼 랜덤수를 생성
    scanf("%d", &N );

    for(i=0; i<N; i++)
    {
        a =  rand()% 101;
        printf("%d ", a); //생성한 랜덤 수를 화면에 출력하기
        fwrite(&a ,sizeof(int),1,file); //동시에 파일에 쓰기
    }

    printf("\n");

    fclose(file);     //파일닫기

    file = fopen("hello.bin", "rb");  //파일을 읽기모드로 열기

    if (!file)
    {
        printf("파일 열기 실패");
        return 1;
    }

    while( g>N || g<0)
    {
        printf("정수를 입력하시오. ");
        scanf("%d", &g ); //입력한 정수번째 숫자를 파일에서 찾아 출력한다.
    }
    
    int k[2];
    fseek(file, g*sizeof(int), SEEK_SET);
    fread(&g, sizeof(int), 1, file);
    fseek(file, -sizeof(int), SEEK_CUR);
    fread(k, sizeof(int), 2, file);

    printf("%d\n",g);

    for(i=0; i<2; i++)
    {
        printf("%d ",k[i]);
    }

    fclose(file);//파일닫기

    return 0;
}
