#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>

struct member
{
    char id[31];
    char name[10];
    char birth[9];
    char phone_number[14];
    char job[10];
    int age;
    char mf;
};

int valid(char *p)
{
    int i;
    char temp[5];

    if(strlen(p) != 13 )
    {
        return 0;
    }
    if(p[3] != '-' || p[8] != '-')
    {
        return 0;
    }
    if(p[0] != '0'|| p[1] != '1' || p[2] != '0')
    {
        return 0;
    }


    return 1;
}
void id_random_generate(struct member* p)
{
    int i , k;

    for(i=0; i<31; i++)
    {
        k = rand() % 3 ;
        if(k==0)
        {
            p->id[i]= rand() % 10 + '0';
        }
        else if(k==1)
        {
            p->id[i]= rand() % 26 + 'a';
        }
        else
        {
            p->id[i]= rand() % 26 + 'A';
        }
    }
}

int main(void)
{

    srand(time(NULL));
    struct member p;

    printf("이름을 입력하시오.\n");
    scanf("%s", p.name);
    printf("주민등록번호 - 뒤 1자리 입력하시오.\n");
    scanf("%s", p.birth);
    printf("직업을 입력하시오.\n");
    scanf("%s", p.job);

    int i;
    char temp[5];

    switch(p.birth[7])
    {
        case '1':
        case '2':
            strcpy(temp, "19");
            strncat(temp, p.birth, 2);
            p.age = 2024 - atoi(temp);
            break;
        case '3':
        case '4':
            strcpy(temp, "20");
            strncat(temp, p.birth, 2);
            p.age = 2024 - atoi(temp);
            break;
    }

    switch(p.birth[7])
    {
        case '1':
        case '3':
            p.mf ='m';
            break;
        case '2':
        case '4':
            p.mf ='f';
            break;
    }

    printf("연락처를 입력하시오: \n");
    scanf("%s", p.phone_number);

    while(valid(p.phone_number) == 0)
    {
        printf("올바른 연락처를 입력하시오: \n");
        scanf("%s", p.phone_number);
    }

    id_random_generate(&p);

    printf("%s\n", p.id);
    printf("%s\n", p.name);
    printf("%s\n", p.birth);
    printf("%s\n", p.phone_number);
    printf("%d\n", p.age);
    printf("%s\n", p.job);
    printf("%c\n", p.mf);

	return 0;
}
