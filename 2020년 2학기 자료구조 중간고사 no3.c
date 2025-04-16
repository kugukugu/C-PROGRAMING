#include <stdio.h>
#include <string.h>

void deleteChars(char *str, char *ch) 
{
	int length =strlen(ch);
	int i,j;
	char *p=str, *p1= str, *p2=str;
	char str1[100]={0};

	for(i=0; p[i]!='\0'; i++) //hello world
	{
		for(j=0; j<length; j++)
		{
			if(p[i]==ch[j])
			{
				p1=&p[i];
				strncat(str1,p2,p1-p2); //p[i]='\0';
				p1+=1;
				p2=p1;
			}
		}
	}
	strcat(str1,p1);
	strcpy(str,str1);

	/*while(p <= str+length)
	{
        strcat(str1, p);
        p+=strlen(p);
        while(*p==0) //hello world
        {
            p++;
        }
	}*/
}

int main()
{
	char str[128];

	strcpy(str, "hello world");
	deleteChars(str, "lo");
	printf("%s\n", str);

	strcpy (str, "Hello world");
	deleteChars(str,"H");
	printf("%s\n", str);

	return 0;
}
