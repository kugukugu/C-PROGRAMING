#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(void)
{
    FILE *src, *dest;
    char* src_file_name = "original.txt";
    char* dest_file_name = "copy.txt";
    char buffer[256];

    src = fopen( src_file_name , "rt");

    if(src == NULL)
    {
        printf("원본 파일을 열 수 없습니다.\n");
        return 1;
    }

    dest = fopen(dest_file_name, "wt");

    if(dest == NULL)
    {
        printf("복사 파일을 열 수 없습니다.\n");
        fclose(src);
        return 1;
    }

    while( fgets(buffer, 256, src) != NULL)
    {
         fputs(buffer, dest);
    }

    fclose(src);
    fclose(dest);

	return 0;
}
