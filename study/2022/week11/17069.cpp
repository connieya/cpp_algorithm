#include "bits/stdc++.h"

using namespace std;

int arr[33][33];
long long dp[33][33][3]; // 0 => 오른쪽 , 1 => 아래쪽 , 2 => 대각선

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    dp[0][1][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) continue;
            if (arr[i][j] == 1) continue;
            if (arr[i][j + 1] == 0) {
                dp[i][j + 1][0] = dp[i][j][0] + dp[i][j][2];
            }
            if (arr[i + 1][j] == 0) {
                dp[i + 1][j][1] = dp[i][j][1] + dp[i][j][2];
            }
            if (i + 1 < n && j + 1 < n) {
                if (arr[i+1][j] == 0 && arr[i][j+1] == 0 && arr[i+1][j+1] == 0 ) {
                    dp[i+1][j+1][2] = dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
                }
            }
        }
    }
    cout << dp[n-1][n-1][0]+dp[n-1][n-1][1]+dp[n-1][n-1][2];
}