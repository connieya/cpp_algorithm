#include "bits/stdc++.h"

using namespace std;

int a[100001];
int dp[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    dp[0] = a[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = a[i];
        if (dp[i-1]+a[i] > a[i]){
            dp[i] = dp[i-1]+a[i];
        }
    }
    int ans = -2147000;
    for (int i = 0; i < n; ++i) {
        ans = max(dp[i],ans);
    }
    cout << ans;

}