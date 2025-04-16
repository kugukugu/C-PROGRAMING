#include <stdio.h>
#include <string.h>

void delChars(char *str, int n, int m)
{
	char *p= str;
	char *p1= str+n;
	char str1[100]={0};

	strncat(str1, p, p1-p); 
	if(strlen(p1)<m)
	{
		strcat(str1,p1+strlen(p1));
	}
	else
	{
		strcat(str1,p1+m);
	}
	strcpy(str,str1);
}

int main() 
{
	char str1[16] ="0123456";

	delChars(str1, 2, 1);
	printf("[%s]\n", str1);

	strcpy(str1, "0123456");
	delChars(str1, 2, 3);
	printf("[%s]\n", str1);

	strcpy(str1, "0123456");
	delChars(str1, 5, 4);
	printf("[%s]\n", str1);

	return 0;
}
