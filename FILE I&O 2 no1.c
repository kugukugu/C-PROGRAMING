#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(void)
{
    srand(time(NULL));

    FILE* file;

    file = fopen("20241120.txt","wt");

    if (!file)
    {
        printf("파일 열기 실패");
        return 1;
    }


    for(int i=0; i< rand() % 31; i++)
    {
        fprintf(file, "%c", 'a');
    }

    fclose(file);

    file = fopen("20241120.txt","rt");

    fseek (file, 0, SEEK_END);

    printf("%d", ftell(file));

    fclose(file);


	return 0;
}
