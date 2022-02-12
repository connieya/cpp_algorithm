#include "bits/stdc++.h"

using namespace std;

long long dp[65][10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < 10; ++i) {
        dp[1][i] = 1;
    }
    for (int i = 2; i < 65; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k <= j; ++k) {
                dp[i][j] += dp[i-1][k];
            }
        }
    }
    while (t--) {
        int n;
        cin >> n;
        long long  ans = 0;
        for (int i = 0; i < 10; ++i) {
            ans += dp[n][i];
        }
        cout << ans << '\n';
    }
}