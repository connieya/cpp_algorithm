#include "bits/stdc++.h"

using namespace std;
int dp[10001];
int arr[21];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cin >> m;
        fill(dp,dp+10000,0);
        dp[0] =1;
        for (int i = 0; i < n; ++i) {
            for (int j = arr[i]; j <=m; ++j) {
                dp[j] += dp[j-arr[i]];
            }
        }
        cout << dp[m] << '\n';
    }
}