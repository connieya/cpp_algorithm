#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
ll dp[101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        dp[i] = dp[i-1]+1;
        for(int j=1; j < i-2; j++) {
            dp[i] = max(dp[i] , dp[j]*(i-j-1));
        }
    }
    cout << dp[n];

}