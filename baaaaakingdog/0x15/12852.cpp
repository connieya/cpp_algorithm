#include "stdio.h"
#include "algorithm"

using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    int dp[n + 1];
    dp[1] = 0;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }
    printf("%d\n", dp[n]);
    int cur = dp[n];
    for (int i = n; i >= 1; --i) {
        if (dp[i] == cur) {
            printf("%d ", i);

        }

        if (dp[i] == dp[i - 1] + 1) {

        } else if (i % 2 == 0 && dp[i] == dp[i / 2] + 1) {
            i = i / 2 + 1;
        } else if (i % 3 == 0 && dp[i] == dp[i / 3] + 1) {
            i = i / 3 + 1;
        }
        cur--;
    }
}