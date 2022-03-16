#include "bits/stdc++.h"

using namespace std;

int dp[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t, time, score;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> time >> score;
        for (int j = t; j >= time; --j) {
            dp[j] = max(dp[j-time]+score,dp[j]);
        }
    }
    cout << dp[t];
}