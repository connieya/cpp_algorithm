#include "bits/stdc++.h"

using namespace std;

char board[101][101];
bool visited[101][101];
int n, m, w, b;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int x, int y, char ch) {
    visited[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    int cnt = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
            if (board[nx][ny] == ch) {
                cnt++;
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    if (ch == 'W') {
        w += cnt * cnt;
    } else {
        b += cnt * cnt;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j]) {
                bfs(i, j, board[i][j]);
            }
        }
    }
    cout << w << ' ' << b;
}