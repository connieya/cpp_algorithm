#include "stdio.h"

int main()
{
    int n , m;
    scanf("%d",&n);
    int dp[41] = {0};
    int vip[41] = {0};
    dp[0] = 1;
    dp[1]= 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] +dp[i-2];
    }
    scanf("%d",&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d",&vip[i]);
    }
    int start = 0;
    int answer =1;
    for (int i = 0; i < m; ++i) {
        int num = vip[i] - start-1;
        answer *= dp[num];
        start = vip[i];
    }
    answer *= dp[n-start];
    printf("%d",answer);
}