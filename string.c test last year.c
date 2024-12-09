#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	int i;
	char instr[100], searchword[100], *p;
	int count = 0;

	printf("input a string: ");
	gets(instr);

	printf("input searchword: ");
	scanf("%s%*c", searchword);

	printf("searchword = %s\n", searchword);

	p = instr;

	while (p = strstr(p, searchword))
	{
		printf("%s\n", p);
		count++;
		p+= strlen(searchword);
	}

	printf("count = %d\n", count);

	return 0;
}
