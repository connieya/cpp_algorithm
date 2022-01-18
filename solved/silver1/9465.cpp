#include "bits/stdc++.h"

using namespace std;

int dp[2][100000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> dp[i][j];
            }
        }
        dp[0][1] += dp[1][0];
        dp[1][1] += dp[0][0];
        for (int i = 2; i < n; ++i) {
            dp[0][i] += max(dp[1][i-1] , max(dp[0][i-2],dp[1][i-2]));
            dp[1][i] += max(dp[0][i-1] , max(dp[1][i-2],dp[0][i-2]));
        }
        cout << max(dp[0][n-1],dp[1][n-1]) << '\n';
    }
}