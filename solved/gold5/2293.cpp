#include "bits/stdc++.h"

using namespace std;

int dp[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,value;
    cin >> n >> k;
    dp[0] =1;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        for (int j = value; j <=k; j++) {
            dp[j] += dp[j-value];
        }
    }
    cout << dp[k];
}