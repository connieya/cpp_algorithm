#include "bits/stdc++.h"

using namespace std;


int arr[51][51];
int tt[51][51];
int dp[51][51];
int n, m, t, ans;
int dx[] = {1, 0, 1};
int dy[] = {0, 1, 1};

int dfs(int x, int y, int total, int time) {
    if (time > t) return 0;
    if (x == n - 1 && y == m - 1) {
        dp[n-1][m-1]= max(total,dp[n-1][m-1]);
        return total;
    }
    int &ret = dp[x][y];
    if(ret != -1) return dp[x][y];
    for (int i = 0; i < 3; ++i) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx >= n || ny >= m) continue;
        dp[nx][ny] = dfs(nx, ny, total + arr[x][y], time + 1 + tt[x][y]);
        dp[nx][ny] = max(dfs(nx, ny, total, time + 1),dp[nx][ny]);
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> tt[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j] = -1;
        }
    }
    dfs(0, 0, 0, 0);
    cout << ans << '\n';
    cout << dp[n-1][m-1];
}