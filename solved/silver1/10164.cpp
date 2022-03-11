#include "bits/stdc++.h"

using namespace std;

int n, m, k;
int dp[16][16];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        dp[1][i] = 1;
    }
    if (k == 0) {
        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j <= m; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    } else {
        int row = (k / m);
        int column = k % m;
        if (column == 0) {
            column = m;
        }else {
            row += 1;
        }
        for (int i = 2; i <= row; ++i) {
            for (int j = 2; j <= column; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        for (int i = row; i <= n; ++i) {
            dp[i][column] = dp[row][column];
        }
        for (int i = column; i <= m; ++i) {
            dp[row][i] = dp[row][column];
        }
        for (int i = row + 1; i <= n; ++i) {
            for (int j = column + 1; j <= m; ++j) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
    }

    cout << dp[n][m];

}