#define _CRT_SECURE_NO_WARNINGS //라인수, 검색어의 출현회수, 총 문자수, 바이트 수, 단어수
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int search_found(char* line, char* searchword)
{
    char* t = line;
    int count = 0;

    while(t = strstr(t, searchword))
    {
        count++;
        t += strlen(searchword);
    }

    return count;
}

int word_count1(char *line)    // el hello word hello hi hello
{
    char* token;
    int count = 0;

    token = strtok(line, " "); // 공백, 탭, 개행 문자를 구분자로 사용
    while ( token != NULL)
    {
        count++;  // 단어를 찾으면 카운트 증가
        token = strtok(NULL, " ");
    }

    return count;
}

int main() {

    FILE* file;
    char line[100];  
    int line_count = 0;
    int characters_count = 0;
    int searchword_found = 0;
    int word_count = 0;
    char searchword[10];
    char filename[100];

    printf("File to read: ");
    scanf("%s", filename);
    getchar();

    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("파일 열기 실패.");
        return 1;
    }

    printf("Word to search: ");
    scanf("%s", searchword);

    
    while (fgets(line, sizeof(line), file) != NULL) 
    {
        line_count++;
        searchword_found += search_found(line, searchword);
        characters_count += strlen(line);
        word_count += word_count1(line);
    }

    printf("Number of lines = %d\n", line_count);
    printf("Number of searchword found = %d\n", searchword_found);
    printf("Number of characters = %d\n", characters_count);
    fseek(file, 0, SEEK_END);
    printf("Size of file = %d bytes\n", ftell(file));
    printf("Number of words = %d\n", word_count);

    fclose(file);

    return 0;
}
