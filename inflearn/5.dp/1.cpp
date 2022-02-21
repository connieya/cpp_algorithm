#include "bits/stdc++.h"

using namespace std;

int dp[46];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i=4; i<=45; i++){
       dp[i] = dp[i-1] +dp[i-2];
    }
    cout << dp[n];
}