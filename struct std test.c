#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct student
{
	char name[10]; //안 띄어 씀
	char addr[10]; //띄어쓰기 해야 됨
	int score;
	char grade;
};

int main(void)
{
	int average, i, j, sum=0;
	struct student s[5], tmp ;
	
	for ( i = 0; i < 5; i++)
	{
		printf("이름: ");
		scanf("%s%*c", s[i].name);

		printf("주소: ");
		gets(s[i].addr);

		printf("점수(정수): ");
		scanf("%d%*c", &s[i].score);
	}

	
	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (s[i].score < s[j].score)
			{
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
		}
	}
	
	/*for (i = 0; i < 3; i++)
	{
		sum += s[i].score;
	}

	average = sum / 3.0;

	for (i = 0; i < 3; i++)
	{
		if (s[i].score > average)
		{
			s[i].grade = 'A';
		}
		else
		{
			s[i].grade = 'B';
		}
	}

	for (i = 0; i < 3; i++)
	{
		printf("%s %c\n", s[i].name, s[i].grade);
	}*/

	printf("\n");

	for (i = 0; i < 5; i++)
	{
		printf("%s %s %d\n", s[i].name, s[i].addr, s[i].score);
	}

	return 0;
}
