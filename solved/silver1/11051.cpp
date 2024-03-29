﻿#include "bits/stdc++.h"
#define MOD 10007

using namespace std;

int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i = 0; i <= n; ++i) {
        dp[i][i] = dp[i][0] = 1;
        for (int j = 1; j < i; ++j) {
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
        }
    }
    cout << dp[n][k];
}