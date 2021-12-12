#include "stdio.h"
#include "algorithm"
#include "cstring"

using namespace std;

int main()
{
    char str[53];
    char answer[53];
    char temp[53];
    scanf("%s",str);
    int len = strlen(str);
    for (int i=0; i<len; i++){
        answer[i] ='z';
    }
    for (int i = 1; i < len; ++i) {
        for (int j = i+1; j < len; ++j) {
            strcpy(temp ,str);
            reverse(temp,temp+i);
            reverse(temp+i,temp+j);
            reverse(temp+j,temp+len);
            if(strcmp(temp,answer) < 0){
                strcpy(answer,temp);
            }
        }
    }
    printf("%s",answer);
}