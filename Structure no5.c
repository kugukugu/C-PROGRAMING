#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>

struct Address
{
    char si[10];
    char ku[10];
    char ro[10];
};

struct student
{
    char name[10];
    int number;
    int score[6];
    struct Address q;
};

void print_struct(struct student *k)
{
    int i;

    printf("%s\n",(*k).name);
    printf("%d\n", (*k).number);

    for(i=0; i<6; i++)
    {
        printf("%d ",  (*k).score[i]);
    }

    printf("\n");

    printf("%s\n", k->q.si);
    printf("%s\n", k->q.ku);
    printf("%s\n", k->q.ro);

}

int main(void)
{
    struct student *p;

    p = (struct student*)malloc(sizeof(struct student));

    scanf("%s", p->name);
    scanf("%d", &p->number);

    int i;

    for(i=0; i<6; i++)
    {
        scanf("%d", &p->score[i]);
    }

    scanf("%s", p->q.si);
    scanf("%s", p->q.ku);
    scanf("%s", p->q.ro);

    print_struct(p);

    free(p);

	return 0;
}
