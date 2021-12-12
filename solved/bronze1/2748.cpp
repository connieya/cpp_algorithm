#include "stdio.h"
long long fibo[91] = {0,1},N,i;

int main()
{
    scanf("%lld",&N);
    while (++i <N) {
        fibo[i+1]= fibo[i] + fibo[i-1];
    }
    printf("%lld",fibo[N]);
}