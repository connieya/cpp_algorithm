#include "stdio.h"
int main(void)
{
    int n;
    scanf("%d",&n);
    int count =0;
    int i;
    for (i = 1; i <= n; ++i) {
        int temp = i;
        while (temp>0){
            temp /= 10;
            count++;
        }
    }
    printf("%d",count);
}