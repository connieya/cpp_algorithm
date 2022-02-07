#include "bits/stdc++.h"

using namespace std;

int n, m, ans = 0;
int board[501][501];
bool visited[501][501];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int sum, int idx, int x, int y) {
    if (idx == 4) {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (!visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(sum + board[nx][ny], idx + 1, nx, ny);
            visited[nx][ny] = false;
        }
    }
}

void shape(int sum, int x, int y) {
    int res = 0;
    // ㅏ
    if (x + 2 < n && y + 1 < m) {
        res = sum + board[x + 1][y] + board[x + 2][y] + board[x + 1][y + 1];
        ans = max(ans, res);
    }
    // ㅜ
    if (x + 1 < n && y + 2 < m) {
        res = sum + board[x][y+1] + board[x][y+2] + board[x + 1][y + 1];
        ans = max(ans, res);
    }
    // ㅓ
    if (x + 2 < n && y - 1 >= 0) {
        res = sum + board[x + 1][y] + board[x + 2][y] + board[x + 1][y - 1];
        ans = max(ans, res);
    }
    // ㅗ
    if (x - 1 >= 0 && y + 2 < m) {
        res = sum + board[x][y+1] + board[x][y+2] + board[x -1][y + 1];
        ans = max(ans, res);
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visited[i][j] = true;
            dfs(board[i][j], 1, i, j);
            visited[i][j] = false;
            shape(board[i][j], i, j);
        }
    }
    cout << ans;
}