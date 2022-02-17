#include "stdio.h"
#include "math.h"
#include "string.h"
#define MAX_BUFFER 512


int KarpRabin(char *Text, int TextSize, int Start, char *Pattern, int PatternSize);

int Hash(char *String, int Size);

int ReHash(char *String, int Start, int Size, int HashPrev, int Coefficient);


int KarpRabin(char *Text, int TextSize, int Start, char *Pattern, int PatternSize) {
    int i = 0;
    int j = 0;
    int Coefficient = pow(2.0,PatternSize-1);

    int HashText = Hash(Text , PatternSize);
    int HashPattern = Hash(Pattern , PatternSize);

    for(i = Start; i <= TextSize - PatternSize; i++)
    {
        HashText = ReHash(Text, i, PatternSize,HashText,Coefficient);
        if (HashPattern == HashText)
        {
            for (j=0; j<PatternSize; j++){
                if (Text[i+j] != Pattern[j]) break;
            }
            if (j>= PatternSize)
                return i;
        }
    }
    return -1;
}

int Hash(char * String , int Size)
{
    int i=0;
    int HashValue = 0;
    for (i=0; i<Size; i++)
    {
        HashValue += (String[i]* pow(2.0,Size-(1+i)));
    }
    return HashValue;
}


int ReHash(char * String , int start , int size , int hashPrev , int Coefficient)
{
    if (start == 0)
        return hashPrev;

    return String[start + size-1] + ( (hashPrev - Coefficient * String[start-1]) * 2);
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
        int position = KarpRabin(Text, strlen(Text) , 0, Pattern ,PatternSize);

        if (position >= 0)
        {
            printf("line ; %d , column : %d : %s ", Line++,position,Text);
        }
    }
    fclose(fp);
    return 0;
}

