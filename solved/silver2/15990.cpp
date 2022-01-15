#include "bits/stdc++.h"
#define MOD 1000000009
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t , n;
    cin >>t;
    long long dp[100002][3] = {0, };
    dp[1][1] = 1 , dp[3][1] = 1;
    dp[2][2] = 1, dp[3][2] = 1;
    dp[3][3] = 1;
    for (int i = 4; i <=100000; ++i) {
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % MOD;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % MOD;
    }
    while (t--) {
        cin >> n;
        cout << (dp[n][1]+dp[n][2]+dp[n][3]) % MOD << '\n';
    }
}