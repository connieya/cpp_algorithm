#include "bits/stdc++.h"

using namespace std;

int dp[1001]; // 가방의 최대 무개는 1000kg
int n,m;

void solve(int weight ,int cost) {
    for (int j = weight; j <= m; ++j) {
       dp[j] = max(dp[j] , dp[j-weight]+cost);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int weight , cost;
        cin >> weight >> cost;
        solve(weight,cost);
    }
    cout << dp[m];
}