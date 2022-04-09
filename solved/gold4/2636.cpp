#include "bits/stdc++.h"

using namespace std;

int cheese[101][101];
int board[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void init(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            board[i][j] = 0;
        }
    }
}

void bfs(int n, int m) {
    init(n, m);
    queue<pair<int, int>> Q;
    board[0][0] = -1;
    Q.push({0, 0});
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (cheese[nx][ny] == 0 && board[nx][ny] == 0) {
                board[nx][ny] = -1;
                Q.push({nx, ny});
            }
            if (cheese[nx][ny] == 1) {
                board[nx][ny]++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] >= 1) {
                cheese[i][j] = 0;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> cheese[i][j];
        }
    }
    int time = 0, ans = 0;
    while (1) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (cheese[i][j] == 1) {
                    cnt++;
                }
            }
        }
        if (cnt == 0) break;
        time++;
        ans = cnt;
        bfs(n, m);
    }
    cout << time << '\n' << ans;
}