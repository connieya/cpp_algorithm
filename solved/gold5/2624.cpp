#include "bits/stdc++.h"

using namespace std;

int dp[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t >> n;
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        int coin, cnt;
        cin >> coin >> cnt;
        for (int j = coin; j <=t && cnt; j+=coin) {
            dp[j] += dp[j-coin];
            cnt--;
        }
        for (int j = 1; j <=t; ++j) {
            cout << dp[j] << ' ';
        }
        cout << '\n';
    }
    cout << dp[t];

}