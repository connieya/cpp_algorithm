#include "bits/stdc++.h"

using namespace std;

char board[1001][1001];
int visited[1001][1001];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


void init(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visited[i][j] = 2;
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
        cin >> board[i];
    }
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    init(n, m);
    int L = 1;
    visited[0][0] = 0;
    while (!Q.empty()) {
        int len = Q.size();
        for (int i = 0; i < len; ++i) {
            int x = Q.front().first;
            int y = Q.front().second;
            if (x == n-1 && y == m-1) {
                cout << L;
                exit(0);
            }
            Q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (board[nx][ny] == '0' && visited[nx][ny] > visited[x][y]) {
                    visited[nx][ny] = visited[x][y];
                    Q.push({nx, ny});
                } else if (board[nx][ny] == '1' && visited[x][y] == 0) {
                    visited[nx][ny] = visited[x][y] + 1;
                    Q.push({nx, ny});
                }
            }
        }
        L++;
    }
    cout << -1;
}