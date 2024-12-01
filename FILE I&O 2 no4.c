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

int compare(struct Student *a, struct Student *b)
{
    return  -(a->score - b->score)*10;
}

void print_std()
{
    int j, count = 0;

    struct Student *p;
    FILE* fp;
    fp = fopen("student.bin", "rb");

    fseek(fp, 0, SEEK_END);

    p = (struct Student*)malloc(ftell(fp));  

    fseek(fp, 0, SEEK_SET);

    while (fread(&p[count], sizeof(struct Student), 1, fp) == 1)
    {
        count++;
    }

    if (count == 0)
    {
        printf("학생 정보가 없습니다.\n");
    }

    qsort(p, count, sizeof(struct Student), compare);

    for ( j = 0; j < count; j++)
    {
        printf("%d %s %.2lf\n", p[j].number, p[j].name, p[j].score);
    }
   
    printf("\n");

    free(p);
    fclose(fp);
}

void menu()
{
    printf("1. 학생 추가\n");
    printf("2. 학생 데이터 출력(성적순)\n");
    printf("3. 학생 성적 수정\n");
    printf("4. 프로그램 종료\n\n");
}

void add_std()
{
    FILE* fp;
    struct Student s ;
    struct Student p;
    fp = fopen("student.bin", "ab+");
    
    printf("학번을 입력하시오. (20240000 ~ 20249999) ");
    scanf("%d", &s.number);
    getchar();

    while (s.number < 20240000 || s.number>20249999)
    {
        printf("다시 입력하시오. ");
        scanf("%d", &s.number);
        getchar();
    }

    fseek(fp, 0, SEEK_SET);

    while (fread(&p, sizeof(struct Student), 1, fp) == 1)
    {
        if(s.number == p.number)
        {
            printf("이미 존재하는 학번입니다. 다시 입력하시오. ");
            scanf("%d", &s.number);
            getchar();
            fseek(fp, 0, SEEK_SET);
        } 
    }
    
    printf("이름을 입력하시오. ");
    gets(s.name);
    fflush(stdin);

    printf("점수를 입력하시오. (0~100점) ");
    scanf("%lf", &s.score);
    getchar();

    while (s.score < 0 || s.score > 100)
    {
        printf("다시 입력하시오. ");
        scanf("%lf", &s.score);
        getchar();
    }

    printf("\n");

    fwrite(&s, sizeof(struct Student), 1, fp);

    fclose(fp);
}

void change_std()
{
    FILE* fp;
    int number1, count=0;
    struct Student p;
    struct Student q;

    fp = fopen("student.bin", "rb+");

    print_std();

    while(1)
    {
        printf("찾을 학생의 학번을 입력하시오. ");
        scanf("%d", &number1);
        
        fseek(fp, 0, SEEK_SET);

        while (fread(&p, sizeof(struct Student), 1, fp) == 1)
        {
            if (number1 == p.number)
            {
                count += 1;
                printf("새로운 점수를 입력하시오. (0~100점) ");
                scanf("%lf", &p.score);

                while (p.score < 0 || p.score > 100)
                {
                    printf("다시 입력하시오. ");
                    scanf("%lf", &p.score);
                }

                fseek(fp, -1 * sizeof(struct Student), SEEK_CUR);
                fwrite(&p, sizeof(struct Student), 1, fp);

                fseek(fp, -1 * sizeof(struct Student), SEEK_CUR);
                fread(&q, sizeof(struct Student), 1, fp);

                printf("%d %s %.2lf\n", q.number, q.name, q.score);

                break;
            }
        }

        if(count == 0)
        {
            printf("\n없습니다.\n\n");
        }
        else
        {
            break;
        }
    }

    printf("\n");

    fclose(fp);
}

int main() 
{
    int M;

    while (1)
    {
        menu();
        printf("메뉴를 선택하시오. ");
        scanf("%d", &M);

        printf("\n");

        while (M < 1 || 4 < M)
        {
            printf("없는 메뉴 입니다. 다시 선택 하십시오. \n");
            scanf("%d", &M);
        }
        
        switch (M)
        { 
            case 1:
                add_std();
                break;
            case 2:
                print_std();
                break;
            case 3:
                change_std();
                break;
            case 4:
                return 0;
        }
    }
    
    return 0;
}
