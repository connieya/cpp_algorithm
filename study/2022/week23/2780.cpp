#include "bits/stdc++.h"

#define MOD 1234567
typedef long long ll;

using namespace std;

ll dp[1001][10]; // 길이와 번호

void solve() {
    fill(dp[1], dp[1] + 10, 1);
    for (int i = 2; i <= 1000; i++) {
        dp[i][0] = dp[i - 1][7] % MOD;
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][4]) % MOD;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5]) % MOD;
        dp[i][3] = (dp[i - 1][2] + dp[i - 1][6]) % MOD;
        dp[i][4] = (dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7]) % MOD;
        dp[i][5] = (dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8]) % MOD;
        dp[i][6] = (dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9]) % MOD;
        dp[i][7] = (dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][0]) % MOD;
        dp[i][8] = (dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9]) % MOD;
        dp[i][9] = (dp[i - 1][6] + dp[i - 1][8]) % MOD;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, length;
    cin >> t;
    solve();
    while (t--) {
        cin >> length;
        ll ans = 0;
        for (int i = 0; i < 10; i++) {
            ans += dp[length][i];
            ans %= MOD;
        }
        cout << ans << '\n';
    }
}