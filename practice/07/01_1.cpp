#include "bits/stdc++.h"

using namespace std;

int arr[46];
int dp[46];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    dp[1] = arr[1];
    for (int i = 2; i < n; ++i) {
        dp[i] = min(dp[i-1]+arr[i] , dp[i-2]+arr[i]);
    }
    cout << min(dp[n-1],dp[n-2]);

}