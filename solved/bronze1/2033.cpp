#include "stdio.h"
int main()
{
    int n , digit = 10 , round =5;
    scanf("%d",&n);
    while (n > digit){
        n += round;
        n = n/digit;
        n *= digit;
        round *= 10;
        digit *= 10;
    }
    printf("%d",n);
}