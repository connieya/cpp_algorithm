#include "bits/stdc++.h"

using namespace std;

int arr[2223][2223];
int dp[2223][2223];

int main()
{
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
    for (int i = 2; i <= n; ++i) {
        if (arr[i-1][1] <= arr[i][1]) {
            dp[i][1] = arr[i][1] - arr[i-1][1]+1;
        }
        if (arr[1][i-1] <= arr[1][i]) {
            dp[1][i] = arr[1][i] - arr[1][i-1]+1;
        }
        dp[i][1] += dp[i-1][1];
        dp[1][i] += dp[1][i-1];
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            int a = 0;
            int b = 0;
            if (arr[i][j] >= arr[i][j-1]) {
                a += arr[i][j] - arr[i][j-1] +1;
            }
            if (arr[i][j] >= arr[i-1][j]) {
                b += arr[i][j] - arr[i-1][j]+1;
            }
            dp[i][j] = min(dp[i-1][j]+b,dp[i][j-1]+a);
        }
    }
    cout << dp[n][n];

}