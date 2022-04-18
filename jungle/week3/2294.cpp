#include "bits/stdc++.h"
#define INF 19999999
using namespace std;

int dp[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    fill(dp, dp + k + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        int coin;
        cin >> coin;
        for (int j = coin; j <= k; ++j) {
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }
    if (dp[k] == INF) {
        cout << -1;
    } else {
        cout << dp[k];
    }

}