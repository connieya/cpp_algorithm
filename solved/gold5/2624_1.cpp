#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, K, coin, cnt;
    int dp[10001] = {1};
    cin >> T >> K;
    for (int i = 0; i < K; ++i) {
        cin >> coin >> cnt;
        for (int money = T; money >= coin; --money) {
            for (int j = 1; j <= cnt; ++j) {
                if (money - coin * j < 0) break;
                dp[money] += dp[money - coin * j];
            }
        }
    }
    cout << dp[T];
}