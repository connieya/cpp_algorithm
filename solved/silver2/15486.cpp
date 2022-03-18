#include "bits/stdc++.h"

using namespace std;

int dp[1500001];
int ans = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int t , p;
        cin >> t  >> p;
        if (i+t <=n) {
            dp[i+t-1] = max(dp[i+t-1],dp[i+t-1]+p);
        }
    }
}
