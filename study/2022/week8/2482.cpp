#include "bits/stdc++.h"
#define INF 1000000003

using namespace std;

long long dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = i;
        dp[i][0] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j*2 <= i+1; ++j) {
            dp[i][j] = (dp[i-2][j-1]+dp[i-1][j]) % INF;
        }
    }
    cout << (dp[n-1][k]+dp[n-3][k-1]) % INF;
}