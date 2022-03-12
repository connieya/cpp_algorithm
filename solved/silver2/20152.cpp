#include "bits/stdc++.h"

using namespace std;

long long dp[31][31];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h, n;
    cin >> h >> n;
    for (int i = 0; i < 31; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 1; i < 31; ++i) {
        for (int j = 1; j < 31; ++j) {
            if (i < j) continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    int s = abs(h-n);
    cout << dp[s][s];

}