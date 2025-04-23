#include <stdio.h>

int main()
{
	int ia[12];
	int count[10]={0};
	int i, high;	

	for(i=0; i<12; i++)
	{
		printf("%d번 째 숫자를 입력하시오. ", i+1);
		scanf("%d", &ia[i]);
	}

	for(i=0; i<12; i++) 
	{
		count[ia[i]-1]++;
	}

	high=count[0];	

	for(i=1; i<10; i++)
	{
		if(high<count[i])
		{
			high=count[i];
		}
	}	
	
	for(i=0; i<10; i++)
	{
		if(high==count[i])
		{
			printf("%d ", i+1);			
		}
	}
	printf("\n");

	return 0; 	
}
