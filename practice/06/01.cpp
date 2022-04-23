#include "bits/stdc++.h"

using namespace std;

char board[101][101];
int dx[] = { 0, 1};
int dy[] = {1, 0};
int n, m;

void bfs(int x, int y) {
    board[x][y] = '.';
    for (int i = 0; i < 2; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            continue;
        }
        if (board[nx][ny] == '#') {
            board[nx][ny] = '.';
            return;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == '#') {
                bfs(i,j);
                ans++;
            }
        }
    }
    cout << ans;
}