#include "bits/stdc++.h"

using namespace std;

int matrix[501][2];
int dp[501][501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> matrix[i][0] >> matrix[i][1];
    }

    for (int len = 2; len <= n; ++len) {
        for (int start = 0; start <= n - len; ++start) {
            dp[start][len + start] = 1e9;
            for (int sep = start + 1; sep < start + len; ++sep) {
                dp[start][start+len] = min(dp[start][start+len] , dp[start][sep] + dp[sep][start+ len] + matrix[start][0] * matrix[sep][0] * matrix[len + start - 1][1]);
            }
        }
    }
    cout << dp[0][n];

}
