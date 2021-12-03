#include "stdio.h"
int main()
{
    char number[100];
    int num[10] ={0} , max = -1 , answer =0;
    scanf("%s",number);
    for (int i = 0; number[i] !=0; ++i) {
        num[number[i]-'0']++;
    }
    for (int i = 0; i<10; ++i) {
       if(num[i] >= max){
           max = num[i];
           answer = i;
       }
    }
    printf("%d",answer);
}