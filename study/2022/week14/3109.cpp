#include "bits/stdc++.h"

using namespace std;

char board[10001][501];
bool visited[10001][501];
int dx[] = {-1, 0, 1};
int dy[] = {1, 1, 1};
int r, c;
int ans;

bool dfs(int x, int y) {
    visited[x][y] = true;
    if (y == c - 1) {
        ans++;
        return true;
    }

    for (int i = 0; i < 3; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= r || nx < 0 || visited[nx][ny] || board[nx][ny] == 'x') continue;
        if (dfs(nx, ny))return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        cin >> board[i];
    }
    for (int i = 0; i < r; ++i) {
        dfs(i, 0);
    }
    cout << ans;
}