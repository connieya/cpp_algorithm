#include "bits/stdc++.h"

using namespace std;

int arr[21][21];
int dp[21][21];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> arr[i][j];
        }
    }

    dp[1][1] = arr[1][1];
    for (int i = 2; i <= n; ++i) {
        dp[1][i] =  dp[1][i-1]+arr[1][i];
        dp[i][1] = dp[i-1][1] + arr[i][1];
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            int res = min( dp[i][j - 1] , dp[i - 1][j] );
            res += arr[i][j];
            dp[i][j] = res;
        }
    }
    cout << dp[n][n];
}