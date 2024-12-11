#include <stdio.h>
#include <stdlib.h>

int main()
{
    char instr[100], replace[100], searchword[100], outstr[100] = {0}, *p, *p2;
    int count =0;

    printf("문자열 1줄을 입력하시오. ");
    gets(instr);

    printf("찾을 문자열을 입력하시오. ");
    gets(searchword);

    printf("바꿀 문자열을 입력하시오. ");
    gets(replace);


    p = instr;
    p2 = instr;

    while(p = strstr(p,searchword))
    {
        count++;
        strncat(outstr, p2, p-p2);
        strcat(outstr, replace);
        p+= strlen(searchword);
        p2=p;

    }

    strcat(outstr, p2);

    printf("count = %d\n", count);
    printf("%s\n", outstr);

    return 0;
}
