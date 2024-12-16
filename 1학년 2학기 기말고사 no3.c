#define _CRT_SECURE_NO_WARNINGS //라인수, 검색어 출현회수, 총 문자수, 바이트 수, 단어수 프린트
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int searchword_c(char* p, char *s)
{
	int count = 0, i=1;
	char* t = p;
	char* z = { 0 };
	char e[100] = { 0 };
	e[0] = toupper(s[0]);

	while (s[i] != '\0')
	{
		e[i] = s[i];
		i++;
	}
	s[i] = '\0';

	z = e;

	while (t = strstr(t, s)) //i love love love you so much!
	{
		count++;
		t += strlen(s);
	}

	t = p;

	while (t = strstr(t, z)) //i love love love you so much!
	{
		count++;
		t += strlen(s);
	}

	return count;
}

int ch_c(char* p)
{
	return strlen(p);
}

int word_c(char* p)
{
	char* token;
	int count = 0;

	token = strtok(p, " ,.:\t\n");

	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ,.:\t\n");
	}

	return count;
}

int main()
{
	FILE* fp;
	char filename[100],searchword[10];
	char buffer[200];

	printf("File to read: ");
	scanf("%s", filename);

	printf("Word to search(non-casesensitive): ");
	scanf("%s", searchword);

	fp = fopen(filename, "rt");

	int line_count = 0;
	int searchword_count = 0;
	int ch_count = 0;
	int word_count = 0;

	while (fgets(buffer, 200, fp) != NULL)
	{
		line_count += 1;
		searchword_count += searchword_c(buffer, searchword);
		ch_count += ch_c(buffer);
		word_count += word_c(buffer);
	}

	printf("Number of lines = %d\n", line_count);
	printf("Number of searchword found = %d\n", searchword_count);
	printf("Number of characters without enter key = %d\n", ch_count);
	printf("Number of words = %d\n", word_count);
	fseek(fp, 0, SEEK_END);
	printf("Number of bytes = %d\n", ftell(fp));

	return 0;
}
