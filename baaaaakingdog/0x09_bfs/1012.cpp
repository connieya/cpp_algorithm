#include "bits/stdc++.h"

using namespace std;

int board[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int m, n, k;
queue<pair<int, int >> Queue;

void bfs(int x, int y) {
    Queue.push({x, y});
    board[x][y] = 0;
    while (!Queue.empty()) {
        auto cur = Queue.front();
        Queue.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == 0) continue;
            board[nx][ny] = 0;
            Queue.push({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n >> k;
        int x ,y;
        while (k--) {
            cin >> x >> y;
            board[y][x] = 1;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 1) {
                    res++;
                    bfs(i,j);
                }
            }
        }
        cout << res << '\n';
    }
}
