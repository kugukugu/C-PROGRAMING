#include <stdio.h>
#include <string.h>
#define MAXLEN 16

int insert (char *str1, char *str2, int n)
{
	char *p=str1;
	char *p1 = p+n;
	char str[100]={0};

	strncat(str,p,n);
	strcat(str,str2);
	strcat(str, p1);
	strcpy(str1,str);
}

int main()
{
	char str1[16]= "hello", str2[16]="World";

	insert(str1, str2, 2);
	printf("[%s]\n", str1);
	
	return 0;
}
