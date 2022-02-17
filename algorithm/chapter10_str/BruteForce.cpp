#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX_BUFFER 512

int BruteForce(char *, int, int, char *, int);

int BruteForce(char * Text , int textSize , int start , char * pattern , int patterSize)
{
    int j;
    for (int i = start; i <= textSize-patterSize; ++i) {
        for (j = 0; j < patterSize; ++j) {
            if (Text[i+j] != pattern[j]) break;

        }
        if (j>= patterSize) return i;
    }
    return -1;
}


int main(int argc , char ** argv)
{
    char * FilePath;
    FILE * fp;

    char Text[MAX_BUFFER];
    char * Pattern;
    int PatternSize = 0;
    int Line = 0;
    if (argc < 3)
    {
        printf("Usage : %s <FilePath> <Pattern > \n" , argv[0]);
        return 1;
    }

    FilePath = argv[1];
    Pattern = argv[2];

    PatternSize = strlen(Pattern);

    if ((fp = fopen(FilePath , "r")) == NULL)
    {
        printf("Cannot open file : %s \n",FilePath);
        return 1;
    }

    while (fgets(Text, MAX_BUFFER , fp) != NULL)
    {
        int position = BruteForce(Text, strlen(Text) , 0, Pattern ,PatternSize);

        if (position >= 0)
        {
            printf("line ; %d , column : %d : %s ", Line++,position,Text);
        }
    }
    fclose(fp);
    return 0;
}

