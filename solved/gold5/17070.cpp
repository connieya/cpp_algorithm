#include "bits/stdc++.h"

using namespace std;

int board[17][17];
int n;
int dx[] = {1, 1, 0, 1};
int dy[] = {1, 0, 1, 1};


int dfs(int direction, int x, int y) {
    if (x == n - 1 && y == n - 1) {
        return 1;
    }
    int cnt = 0;
    if (direction == 0 || direction == 3) { // 대각선
        for (int i = 0; i < 3; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= n || ny >= n || board[nx][ny] == 1) continue;
            if (i == 0 && (board[x + 1][y] || board[x][y + 1])) continue;
            cnt += dfs(i, nx, ny);
        }
    } else if (direction == 1) { // 세로
        for (int i = 0; i < 2; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= n || ny >= n || board[nx][ny] == 1) continue;
            if (i == 0 && (board[x + 1][y] || board[x][y + 1])) continue;
            cnt += dfs(i, nx, ny);
        }
    } else if (direction == 2) { // 가로
        for (int i = 2; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= n || ny >= n || board[nx][ny] == 1) continue;
            if (i == 3 && (board[x + 1][y] || board[x][y + 1])) continue;
            cnt += dfs(i, nx, ny);
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    cout << dfs(2, 0, 1) << '\n';
}