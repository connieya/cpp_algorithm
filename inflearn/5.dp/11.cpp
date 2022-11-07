#include "bits/stdc++.h"

using namespace std;

int dp[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,score,time;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> score >> time;
        for (int j = m; j >=time; --j) {
            dp[j] = max(dp[j] , dp[j-time]+score);
        }
    }
    cout << dp[m];
}