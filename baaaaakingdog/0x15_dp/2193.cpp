#include "bits/stdc++.h"

using namespace std;

long long dp[91][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    dp[1][0] = 0;
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    cout << dp[n][0] + dp[n][1];
}