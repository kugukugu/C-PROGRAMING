#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 5

struct STD
{
	char name[100];
	int score;
	int ranking;
	char pass;
};

int compare(struct STD* s, struct STD* q)
{
	return -(s->score - q->score);
}

int main()
{
	int i;
	struct STD s[SIZE];

	printf("Input name and score:\n");

	for (i = 0; i < SIZE; i++)
	{
		printf("name = ");
		gets(&s[i].name);
		printf("score = ");
		scanf("%d%*c", &s[i].score);
	}

	printf("-------- before -----------\n");
	printf("Name            Score\n");

	for (i = 0; i < SIZE; i++)
	{
		printf("%-10s %10d\n", s[i].name, s[i].score);
	}

	qsort(s, SIZE, sizeof(struct STD), compare);

	printf("-------- after -----------\n");
	printf("Name            Score    Ranking       P/NP\n");

	for (i = 0; i < SIZE; i++)
	{
		s[i].ranking = i + 1;
		if (SIZE * (2.0 / 3.0) > (double)i + 1)
		{
			s[i].pass = 'P';
		}
		else
		{
			s[i].pass = 'N';
		}
	}

	for (i = 0; i < SIZE; i++)
	{
		printf("%-10s %10d %10d %10c\n", s[i].name, s[i].score, s[i].ranking, s[i].pass);
	}

	return 0;
}
