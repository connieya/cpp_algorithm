#include "bits/stdc++.h"

#define MOD 1000000007

using namespace std;

long long dp[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i-1];
        if (i-m>=0) {
            dp[i] = (dp[i] + dp[i-m]) % MOD;
        }
        cout << dp[i] << '\n';
    }
    cout << dp[n];

}