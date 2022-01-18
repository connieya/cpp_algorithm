#include "bits/stdc++.h"

using namespace std;

int dp[1000][3];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
    }
    for (int i = 1; i < n; ++i) {
        dp[i][0] += min(dp[i-1][1] , dp[i-1][2]);
        dp[i][1] += min(dp[i-1][0] , dp[i-1][2]);
        dp[i][2] += min(dp[i-1][1] , dp[i-1][0]);
    }
    cout << min(dp[n-1][0], min(dp[n-1][1],dp[n-1][2]));
}