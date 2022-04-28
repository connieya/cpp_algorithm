#include "bits/stdc++.h"

using namespace std;

int arr[301];
int dp[301];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <=n ; ++i) {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    dp[2] = arr[1]+arr[2];
    for (int i = 3; i <=n ; ++i) {
        int a = arr[i]+arr[i-1]+dp[i-3];
        int b = arr[i]+dp[i-2];
        dp[i] =  max(a,b);
    }
    cout << dp[n];
}
