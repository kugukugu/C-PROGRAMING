#include <stdio.h>
#include <stdlib.h>

void transfer_scale_up(int width, int height, int channel, int scale, char**p, char**q);

int main()
{
    FILE * fin, *fout ;

    char ifilename[10];
    char ofilename[10];
    char **p, **q;

    int i, j, k;

    printf("읽을 파일을 입력하시오. ");
    scanf("%s", ifilename);
    getchar();

    printf("쓸 파일을 입력하시오. ");
    scanf("%s", ofilename);
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

    char magic[3]; int width, height, channel=1;

    fscanf(fin, "%s%d%d", magic, &width, &height);

    if(strcmp("P6",magic)==0)
    {
        channel = 3;
    }

    fprintf(fout, "%s %d %d 255\n", magic, width*scale, height*scale);

    fseek(fin, -1*width*height*channel, SEEK_END);

    p = (char **)malloc(height * sizeof(char*));
    q = (char **)malloc(height * sizeof(char*)*scale);

    for(i=0; i<height; i++)
    {
        p[i]=(char*)malloc(sizeof(char)*width*channel);
        fread(p[i], sizeof(char), width*channel, fin);
    }

    for(i=0; i<height * scale; i++)
    {
        q[i]=(char*)malloc(sizeof(char)*width*channel*scale);
    }

    transfer_scale_up(width, height, channel, scale, p, q);

    for(i=0; i<height * scale; i++)
    {
       fwrite(q[i],sizeof(char), width*channel*scale,fout);
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

void transfer_scale_up(int width, int height, int channel, int scale, char**p, char**q)
{
    int i, j, k, k2;

    for(i=0; i<height; i++)
    {
        for(j=0; j<width*channel; j++)
        {
            for(k=0; k<scale; k++)
            {
                for(k2=0; k2<scale; k2++)
                {
                    q[i*scale+k][j*scale+k2] = p[i][j];
                }
            }
        }
    }
}
