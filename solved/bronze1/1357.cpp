#include "stdio.h"

int reverseNum(int num){
    int digit = 0;
    while (num > 0){
        digit = digit*10 + num % 10;
        num = num/10;
    }
    return digit;
}
int main()
{
    int x, y;
    scanf("%d %d",&x,&y);
    int sum = reverseNum(x)+ reverseNum(y);
    printf("%d", reverseNum(sum));
}