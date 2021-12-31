#include "stdio.h"

int main(void)
{
    int n;
    long long dp[91];
    dp[1] = 1;
    dp[2] = 1;
    scanf("%d",&n);
    for (int i = 3; i <=n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    printf("%lld",dp[n]);
}