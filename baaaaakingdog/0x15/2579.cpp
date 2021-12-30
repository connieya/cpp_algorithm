#include "stdio.h"
#include "algorithm"

using namespace std;
int main(void) {
    int n;
    scanf("%d", &n);
    int dp[302][3];
    int tmp[302];
    for (int i = 1; i <= 4; ++i) {
        scanf("%d", &tmp[i]);
    }
    dp[1][1] = dp[1][2] = tmp[1];
    dp[2][1] = dp[2][2] = tmp[2]+tmp[1];
    dp[3][1] = tmp[3] + tmp[1];
    dp[3][2] = tmp[3] + tmp[2];
    dp[4][1] = tmp[4] + tmp[2] + tmp[1];
    dp[4][2] = tmp[4] + tmp[3] + tmp[1];
    for (int i = 5; i <=n; ++i) {
        scanf("%d", &tmp[i]);
        dp[i][1] = tmp[i] + max(dp[i - 2][1] , dp[i - 2][2]);
        dp[i][2] = tmp[i] + dp[i-1][1];
    }

    printf("%d", max(dp[n][1],dp[n][2]));
}