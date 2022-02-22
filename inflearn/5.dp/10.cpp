#include "bits/stdc++.h"

using namespace std;

int arr[13];
int dp[501];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n ,m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> m;
    fill(dp,dp+501,INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = arr[i]; j <=m; j++) {
            dp[j] = min(dp[j],dp[j-arr[i]]+1);
        }
    }
    cout << dp[m];
}