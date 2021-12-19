#include "stdio.h"

int main(void)
{
    int a ,b , m;
    scanf("%d %d %d",&a,&b,&m);
    long long val =1;
    while (b--) {
        val = val * a % m;
    }
    printf("%d" , val);
}