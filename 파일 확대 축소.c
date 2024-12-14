#include <stdio.h>
#include <stdlib.h>

void transfer_scale_up(int width, int height, int channel, int scale, char**p, char**q);
void transfer_scale_down(int width, int height, int channel, int scale, char**p, char**q);

int main()
{
    FILE * fin, *fout, *fout2 ;

    char ifilename[10];
    char ofilename[10];
    char ofilename2[10];
    char **p, **q, **t;

    int i, j, k;

    printf("읽을 파일을 입력하시오. ");
    scanf("%s", ifilename);
    getchar();

    printf("쓸 파일을 입력하시오. ");
    scanf("%s", ofilename);
    getchar();

    printf("쓸 파일을 입력하시오. ");
    scanf("%s", ofilename2);
    getchar();

    int scale;

    printf("enter scale: ");
    scanf("%d%*c", &scale);

    fin = fopen(ifilename, "rb");
    if(fin==NULL)
    {
        printf("읽을 파일을 열 수 없습니다. ");
        return 1;
    }

    fout = fopen(ofilename, "wb");
    if(fout==NULL)
    {
        printf("쓸 파일을 열 수 없습니다. ");
        return 1;
    }

    fout2 = fopen(ofilename2, "wb");
    if(fout2==NULL)
    {
        printf("쓸 파일을 열 수 없습니다. 1");
        return 1;
    }

    char magic[3]; int width, height, channel=1;

    fscanf(fin, "%s%d%d", magic, &width, &height);

    if(strcmp("P6",magic)==0)
    {
        channel = 3;
    }

    fprintf(fout, "%s %d %d 255\n", magic, width*scale, height*scale);
    fprintf(fout2, "%s %d %d 255\n", magic, width/scale, height/scale);

    fseek(fin, -1*width*height*channel, SEEK_END);

    p = (char **)malloc(height * sizeof(char*));
    q = (char **)malloc(height * sizeof(char*)*scale);
    t = (char **)malloc(height *sizeof(char*) / scale);


    for(i=0; i<height; i++)
    {
        p[i]=(char*)malloc(sizeof(char)*width*channel);
        fread(p[i], sizeof(char), width*channel, fin);
    }

    for(i=0; i<height * scale; i++)
    {
        q[i]=(char*)malloc(sizeof(char)*width*channel*scale);
    }

    for(i=0; i< height / scale; i++)
    {
        t[i]=(char*)malloc(sizeof(char)*(width/scale)*channel);
    }

    transfer_scale_up(width, height, channel, scale, p, q);
    transfer_scale_down(width, height, channel, scale, p, t);

    for(i=0; i<height * scale; i++)
    {
       fwrite(q[i],sizeof(char), width*channel*scale,fout);
    }

    for(i=0; i<height / scale; i++)
    {
       fwrite(t[i],sizeof(char), (width/scale)*channel,fout2);
    }

    printf("파일 복사 완료.\n");

    for(i=0; i<height; i++)
    {
        free(p[i]);

    }

    for(i=0; i<height*scale; i++)
    {
        free(q[i]);

    }

    for(i=0; i<height/scale; i++)
    {
        free(t[i]);

    }

    free(p);
    free(q);
    free(t);

    fclose(fin);
    fclose(fout);
    fclose(fout2);

    return 0;
}

void transfer_scale_up(int width, int height, int channel, int scale, char**p, char**q)
{
    int i, j, k1, k2, k;

    if(channel == 1)
    {
        for(i=0; i<height; i++)
        {
            for(j=0; j<width; j++)
            {
                for(k1=0; k1<scale; k1++)
                {
                    for(k2=0; k2<scale; k2++)
                    {
                        q[i*scale+k1][j*scale+k2] = p[i][j];
                    }
                }
            }
        }
    }
    else
    {
        for(i=0; i<height; i++)
        {
            for(j=0; j<width; j++)
            {
                for(k1=0; k1<scale; k1++)
                {
                    for(k2=0; k2<scale; k2++)
                    {
                       for(k=0; k<channel; k++)
                       {
                           q[i*scale+k1][(j*scale+k2)*channel+k] = p[i][j*channel +k];
                       }
                    }
                }
            }
        }
    }
}

void transfer_scale_down(int width, int height, int channel, int scale, char**p, char**t)
{
    int i, j, k1, k2;

    if(channel == 1)
    {
        for(i=0; i<height/scale; i++)
        {
            for(j=0; j<width/scale; j++)
            {
                t[i][j] = p[i*scale][j*scale];
            }
        }
    }
    else
    {
        for(i=0; i<height/scale; i++)
        {
            for(j=0; j<width/scale; j++)
            {
                for(k1=0; k1<channel; k1++)
                {
                    t[i][j*channel +k1] = p[i*scale][(j*scale)*channel+k1];
                }
            }
        }
    }
}
