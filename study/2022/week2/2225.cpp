#include "bits/stdc++.h"
#define MOD 1000000000
using namespace std;

long long dp[201][201];


int main(void) {
    int n, k;
    cin >> n >> k;
    dp[0][0]  = 1LL;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int l = 0; l <= j; ++l) {
                dp[j][i] += dp[j - l][i - 1];
                dp[j][i] %= MOD;
            }
        }
    }
    cout << dp[n][k];
}