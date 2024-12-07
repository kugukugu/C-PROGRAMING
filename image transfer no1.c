#include <stdio.h>
#include <stdlib.h>

void transfer_matrix_lr(int height, int width, int channel, char**q, char**p);
void transfer_matrix_ud(int height, int width, int channel, char**q, char**p);

int main()
{
    FILE * fin, *fout, *fout2;

    char ifilename[10];
    char ofilename[10];
    char a[100];

    int i, j, k;

    printf("읽을 파일을 입력하시오. ");
    scanf("%s", ifilename);
    getchar();

    printf("쓸 파일을 입력하시오. ");
    scanf("%s", ofilename);
    getchar();

    fin = fopen(ifilename, "rb");
    if(fin==NULL)
    {
        printf("읽을 파일을 열 수 없습니다. ");
        return 1;
    }

    sprintf(a,"%s%s", "lr_",ofilename);
    fout = fopen(a, "wb");
    if(fout==NULL)
    {
        printf("쓸 파일을 열 수 없습니다. ");
        return 1;
    }

    sprintf(a,"%s%s", "ud_", ofilename);
    fout2 = fopen(a, "wb");
    if(fout2==NULL)
    {
        printf("쓸 파일을 열 수 없습니다. ");
        return 1;
    }

    char magic[3]; int width, height, channel=1;

    fscanf(fin, "%s%d%d", magic, &width, &height);

    if(strcmp("P6",magic)==0)
    {
        channel = 3;
    }

    fprintf(fout, "%s %d %d 255\n", magic, width, height);
    fprintf(fout2, "%s %d %d 255\n", magic, width, height);

    fseek(fin, -1*width*height*channel, SEEK_END);

    char **p; char **q;

    p = (char **)malloc(height * sizeof(char*));
    q = (char **)malloc(height * sizeof(char*));

    for(i=0; i<height; i++)
    {
        p[i]= (char *)malloc(width * sizeof(char) * channel);
        fread(p[i], sizeof(char), width*channel, fin);
        q[i]= (char *)malloc(width * sizeof(char) * channel);
    }

    transfer_matrix_lr(height, width, channel, q, p);

    for(k=0; k<height; k++)
    {
        fwrite(q[k], sizeof(char) ,width*channel, fout);
    }

    transfer_matrix_ud(height, width, channel, q, p);

    for(k=0; k<height; k++)
    {
        fwrite(q[k], sizeof(char) ,width*channel, fout2);
    }

    printf("파일 복사 완료.\n");

    for(i=0; i<height; i++)
    {
        free(p[i]);
        free(q[i]);
    }

    free(p);
    free(q);

    fclose(fin);
    fclose(fout);

    return 0;
}

void transfer_matrix_lr(int height, int width, int channel, char**q, char**p)
{
    int i, j, k;

    if(channel == 1)
    {
        for(i=0; i<height; i++)
        {
            for(j=0; j<width; j++)
            {
                q[i][j]= p[i][width -1 -j];
            }
        }
    }
    else
    {
        for(i=0; i<height; i++)
        {
            for(j=0; j<width; j++)
            {
                for(k=0; k<channel; k++)
                {
                    q[i][j*channel+k]= p[i][(width-1-j)*channel+k];
                }
            }
        }
    }
}

void transfer_matrix_ud(int height, int width, int channel, char**q, char**p)
{
    int j,i;

    //for(i=0; i<height; i++)
    //{
    //    q[i]=p[height-1-i];
    //}
     for(i=0; i<width*channel; i++)
        {
           for(j=0; j<height; j++)
           {
               q[j][i]= p[height-1-j][i];
           }
        }
}
