#include "stdio.h"

int main()
{
    int n ,tmp, i,cnt = 0 ,digit = 0;
    scanf("%d",&n);
    for (i = 1; i<=n; i++){
        tmp = i;
        while (tmp > 0){
            digit = tmp % 10;
            tmp = tmp/ 10;
            if(digit == 3){
                cnt++;
            }
        }
    }
    printf("%d",cnt);
}