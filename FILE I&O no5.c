#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct
{
    char name[50];
    int score[3];
    float avg;
} Student;

int main(void)
{
   FILE* file;
   Student s = {"홍길동", {91, 83, 80}, 0.0f};
   Student s2;

   file = fopen("student.bin", "wb");

   if(file == NULL)
   {
       printf("파일을 열 수 없습니다.\n");
       return 1;
   }

   fwrite(&s, sizeof(Student),1,file);

   fclose(file);

    printf("구조체 데이터를 파일에 저장 했습니다.\n");

    file = fopen("student.bin", "rb");

   if(file == NULL)
   {
       printf("파일을 열 수 없습니다.\n");
       return 1;
   }

   fread(&s2, sizeof(Student),1,file);

   fclose(file);

   printf("%s", s2.name);

	return 0;
}
