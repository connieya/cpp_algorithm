#include "bits/stdc++.h"

using namespace std;

int arr[21][21];
int dp[21][21];
int n;
int dx[] = {0, 1};
int dy[] = {1, 0};
void dfs(int x, int y, int sum) {
    if (x == n - 1 && y == n - 1) {
        return;
    }
    for (int i = 0; i < 2; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= n || ny >= n || sum+arr[nx][ny] > dp[nx][ny]) continue;
        dp[nx][ny] = sum+arr[nx][ny];
        dfs(nx,ny , sum+arr[nx][ny]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = INT_MAX;
        }
    }
    dfs(0,0,arr[0][0]);
    cout << dp[n-1][n-1];
}