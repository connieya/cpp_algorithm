#include "bits/stdc++.h"

#define MOD 10007
using namespace std;

long long dp[1001][10];
/*
 점화식 dp[i][j] = 길이가 i이고 마지막 숫자가 j인 오르막 개수
 dp[1][i] = 1
 dp[i][j] += dp[i-1][k]  ( 0<= k <= j)
  */
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < 10; ++i) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k <= j; ++k) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        ans = (ans + dp[n][i]) % MOD;
    }
    cout << ans;
}