#include "bits/stdc++.h"
#define INF 1e6
using namespace std;


int n, m;
vector<int> graph[101];
int dp[101][101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            dp[i][j] = INF;
        }
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        dp[a][b] = 1;
        dp[b][a] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; j++) {
              dp[i][j] = min(dp[i][j] , dp[i][k]+dp[k][j]);
            }
        }
    }

    int x, y, ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int sum = 0;
            for (int k = 1; k <= n; k++) {
                sum += min(dp[i][k], dp[j][k]) * 2;
            }
            if (ans > sum) {
                ans = sum;
                x = i;
                y = j;
            }
        }
    }
    cout << x << ' ' << y << ' ' << ans;

}