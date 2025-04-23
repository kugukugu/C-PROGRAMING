#include <stdio.h>

void myStrncpy(char *dest, char *src, int len)
{
	int count = 1;
	while(count<=len)
	{
		*dest=*src;
		*dest++;
		*src++;
		if(*src==0)
		{
			break;
		}	
		count++;
	}
	*dest='\0';
}

int main()
{
	char s[128]="Hello World! Welcome To C";
	char d[128];

	myStrncpy (d, s, 5);
	printf("[%s]\n", d);

	myStrncpy(d, s, 100);
	printf("[%s]\n", d);

	return 0;
}
