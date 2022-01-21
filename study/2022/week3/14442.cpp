#include "bits/stdc++.h"

using namespace std;

int board[1001][1001];
int ans[1001][1001][11];
bool visited[1001][1001][11];

int n, m, k;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    string input;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        for (int j = 0; j < m; ++j) {
            board[i][j] = input[j] - '0';
        }
    }
    queue<pair<pair<int, int>, int>> Q;
    Q.push({{0, 0}, 0});
    ans[0][0][0] = 1;
    visited[0][0][0] = true;
    while (!Q.empty()) {
        auto cur = Q.front();
        int x = cur.first.first;
        int y = cur.first.second;
        int z = cur.second;
        if (x == n - 1 && y == m - 1) {
            cout << ans[x][y][z];
            return 0;
        }
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (board[nx][ny] == 0 && !visited[nx][ny][z]) {
                visited[nx][ny][z] = true;
                ans[nx][ny][z] = ans[x][y][z] + 1;
                Q.push({{nx, ny}, z});
            }
            if (board[nx][ny] == 1 && !visited[nx][ny][z + 1] && z < k) {
                visited[nx][ny][z + 1] = true;
                ans[nx][ny][z + 1] = ans[x][y][z] + 1;
                Q.push({{nx, ny}, z + 1});
            }
        }
    }
    cout << -1;
}