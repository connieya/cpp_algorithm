#include "bits/stdc++.h"

using namespace std;
const int mx = 1e6;
const int mod = 1e9+9;
long long dp[mx+1];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >>t;
    dp[1] =1 ,dp[2] = 2 , dp[3] =4;
    for (int i = 4; i <= mx; ++i) {
        dp[i] = (dp[i-1]+dp[i-2]+dp[i-3]) % mod;
    }
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}