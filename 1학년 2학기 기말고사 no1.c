#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char line[100], searchword[10], change_word[100] = { 0 }, * p, * p1, outline[100] = { 0 };
	printf("Type one line: \n");
	gets(line);

	printf("Type in search-word to capitalize: ");
	scanf("%s%*c", searchword);

	int i = 0;;
	int count = 0;

	while (searchword[i]!='\0')
	{
		change_word[i] = toupper(searchword[i]);
		
		i++;
	}
	change_word[i] = '\0';

	p = line;
	p1 = line;

	while (p = strstr(p, searchword)) //i love love love you so much!
	{
		count++;
		strncat(outline, p1, p - p1);
		strcat(outline, change_word);
		p += strlen(searchword);
		p1 = p;
	}
	
	strcat(outline, p1);
	printf("%d matches are capitalized.\n", count);
	printf("Result: %s", outline);
	
	return 0;
}
