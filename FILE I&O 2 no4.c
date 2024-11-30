#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int number;
    char name[10];
    double score;
};

int menu()
{
    int n;
    printf("1. 학생 추가\n"); 
    printf("2. 학생 데이터 출력(성적순)\n"); 
    printf("3. 학생 성적 수정\n");
    printf("4. 프로그램 종료\n");

    scanf("%d", &n);
    while (n < 1 || n>4)
    {
        printf("다시 입력하시오. ");
        scanf("%d", &n);
    }

    return n;
}

int main() 
{

    FILE* fp;
    struct Student s = { 0 };
    while (1)
    {
        switch (menu())
        { 
            case 1:
                fp = fopen("student.bin", "ab");
                printf("추가할 학생의 정보를 입력하시오. (학번, 이름, 성적)\n");
                printf("학번: ");
                getchar();
                scanf("%d", &s.number);
                printf("이름: ");
                gets(&s.name);
                getchar();
                printf("성적: ");
                scanf("%lf", &s.score);
                getchar();
                fwrite(&s, sizeof(struct Student), 1, fp);
                break;
            case 2:


                break;
            case 3:


                break;
            case 4:


                break;
        }
        
  
      
    }
    
    return 0;
}
