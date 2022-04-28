#include "bits/stdc++.h"

using namespace std;

int dp[10001];
int cnt[1001];
int coin[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t >> n;
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> coin[i] >> cnt[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = t; j >= 1; --j) {
            for (int k = 1; k <= cnt[i]; ++k) {
                if (j - coin[i] * k >= 0) {
                    dp[j] += dp[j - coin[i] * k];
                }
            }
        }
    }
    cout << dp[t];
}