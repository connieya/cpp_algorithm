#include "bits/stdc++.h"

#define MOD 1000000007
using namespace std;

long long dp[1002][1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1 && j == 1) continue;
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[n][m];
}