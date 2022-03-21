#include "bits/stdc++.h"

using namespace std;


int dp[10001];
int wine[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> wine[i];
    }
    dp[1] = wine[1];
    dp[2] = wine[1]+wine[2];
    for (int i = 3; i <= n; ++i) {
        dp[i] = max(dp[i-3]+wine[i-1]+wine[i] , dp[i-2]+ wine[i]);
        dp[i] = max(dp[i-1],dp[i]);
    }
    cout << dp[n];
}