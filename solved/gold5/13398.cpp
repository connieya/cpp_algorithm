#include "bits/stdc++.h"

using namespace std;

int arr[100001];
int dp[100001];
int dp2[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n ,ans;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    ans = dp[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = arr[i];
        if(arr[i] < arr[i]+dp[i-1]){
            dp[i] = arr[i]+dp[i-1];
        }
        ans = max(dp[i],ans);
    }

    dp2[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; --i) {
        dp2[i] = arr[i];
        if(arr[i] < arr[i]+dp2[i+1]){
            dp2[i] = arr[i]+dp2[i+1];
        }
    }

    for (int i = 1; i < n-1; ++i) {
        ans = max(ans, dp[i-1]+dp2[i+1]);
    }
    cout << ans;
}