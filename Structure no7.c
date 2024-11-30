#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>

struct member
{
    char name[10];
    int age;
};

int compare(struct member* a, struct member* b)
{
    return strcmp(a->name, b->name);

}

int main(void)
{

    srand(time(NULL));

    struct member s[10];

    int i, j, N;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < rand() % 11 + 2; j++)
        {
            s[i].name[j] = rand() % 26 + 'a';
        }
        s[i].name[j] = '\0';
        s[i].age = rand() % 100 + 1;

        printf("%s %d\n", s[i].name, s[i].age);
    }

    printf("\n");

    qsort(s, 10, sizeof(struct member), compare);

    for (i = 0; i < 10; i++)
    {
        printf("%s %d\n", s[i].name, s[i].age);
    }

    printf("나이대를 입력하시오. (10 단위)");
    scanf("%d", &N);

    printf("%d대 나이: ", N);

    j = 0;

    for (i = 0; i < 10; i++)
    {
        if (s[i].age - N  >= 0 &&  s[i].age - N  < 10)
        {
            printf("%d ", s[i].age);
            j++;
        }
    }

    if (j == 0)
    {
        printf("존재하지 않습니다.\n");
    }

    return 0;
}
