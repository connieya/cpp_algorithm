#include "bits/stdc++.h"

using namespace std;

int dp[502][502];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <=i; ++j) {
            cin >> dp[i][j];
            dp[i][j] += max(dp[i-1][j-1] , dp[i-1][j]);
        }
    }
    int ans =0;
    for (int i = 1; i <= n ; ++i) {
        ans = max(ans , dp[n][i]);
    }
    cout << ans;
}