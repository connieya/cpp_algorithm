#include "bits/stdc++.h"

using namespace std;

int dp[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int weight , cost;
        cin >> weight >> cost;
        for (int j = weight; j <= k; ++j) {
            dp[j] = max(dp[j-weight]+cost , dp[j]);
        }
    }
    cout << dp[k];
}