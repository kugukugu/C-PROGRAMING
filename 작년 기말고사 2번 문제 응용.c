#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student1
{
	char name[100];
	int score;
};

int compare( struct student1 *q, struct student1 *p)
{
	return strcmp(q->name, p->name);

}

int main(void)
{
	struct student1 s[3], tmp;
	int i;

	for (i = 0; i < 3; i++)
	{
		printf("%d 번째 학생의 이름을 입력하시오. ",i+1);
		gets(s[i].name);

		printf("%d 번째 학생의 점수를 입력하시오. ", i + 1);
		scanf("%d", &s[i].score);
		getchar();
	}

	qsort(s, 3, sizeof(struct student1), compare);
	printf("\n");

	for (i = 0; i < 3; i++)
	{
		printf("%-15s%3d\n", s[i].name, s[i].score);
	}

	return 0;
}
