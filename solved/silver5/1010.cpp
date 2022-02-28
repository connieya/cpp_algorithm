#include "bits/stdc++.h"

using namespace std;

int dp[30][30];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i < 30; ++i) {
        dp[i][0] = dp[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    while (t--) {
        int a ,b;
        cin >> a>> b;
        cout << dp[b][a] << '\n';
    }
}