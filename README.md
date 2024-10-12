#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define PI 3.141592

double rad(double degree) 
{
    return PI * degree / 180.0; 
}

void drawbar(int height)
{
    for (int i = 0; i < 30; i++)
    {
        printf(" ");
    }
    for (int i = 0; i <= height; i++)
    {
        printf("*");
    }
    printf("\n");
}

void drawbar1(int height)
{
    for (int i = 0; i < height; i++)
    {
        printf(" ");
    }
    for (int i = height; i <= 30; i++)
    {
        printf("*");
    }
    printf("\n");
}

int main(void) 
{
    int degree, y;

    for (degree = 0; degree < 180; degree += 10)
    {
        y = (int)(30 * sin(rad((double)degree)) + 0.5); 
        drawbar(y); 
    }

    for (degree = 180; degree <= 360; degree += 10)
    {
        y = (int)(30 * (1 + sin(rad((double)degree))) + 0.5);
        drawbar1(y); 
    }

    return 0;
}
