#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
    int i= -1;

    FILE *file = fopen("test.txt", "r");

    if( file == NULL)
    {
        printf("파일 열기 실패");
        return 1;
    }

    while(fseek(file,i--,SEEK_END)==0)
    {
        printf("%c", fgetc(file));
    }

    printf("\n");

    fclose(file);

    return 0;
}
