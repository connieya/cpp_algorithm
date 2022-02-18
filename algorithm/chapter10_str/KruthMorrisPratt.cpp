#include "stdio.h"
#include "stdlib.h"

int border[200];

int KnuthMorrisPratt(char *, int, int, char *, int);

void Preprocess(char *, int, int *);

void Preprocess(char *pattern, int patternSize, int *border) {
    int i = 0;
    int j = -1;
    border[0] = -1;

    while (i < patternSize) {
        while (j > -1 && pattern[i] != pattern[j]) {
            j = border[j];
            i++;
            j++;

            border[i] = j;
        }
    }
}

int KnuthMorrisPratt(char *text, int textSize, int start, char *pattern, int patternSize) {
    int i = start;
    int j = 0;
    int position = -1;

    int *border = (int *) calloc(patternSize + 1, sizeof(int));

    Preprocess(pattern,patternSize,border);
    while (i<textSize) {
        while (j >= 0 && text[i] != pattern[j])
            j = border[j];

        i++;
        j++;

        if (j == patternSize)
        {
            position = i-j;
            break;
        }
    }
    free(border);
    return position;
}


int main()
{
     char * pattern = "abcde";
     int size = sizeof(pattern) / sizeof(char );
    Preprocess(pattern,size , border);
    char * text = "adadadsdadddsabcdedsdad";
    int textSize = sizeof(text) / sizeof(char );
    int ans = KnuthMorrisPratt(text, textSize , 0,pattern,size );
    printf("find index :  %d" , ans);

}