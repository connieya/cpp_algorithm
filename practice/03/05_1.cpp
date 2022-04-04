#include "bits/stdc++.h"

using namespace std;

int board[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
            if (!board[i][j]) {
                board[i][j] = -1;
            }
        }
    }
    int tomX, tomY, jerryX, jerryY;
    cin >> tomX >> tomY >> jerryX >> jerryY;
    board[tomX][tomY] = 0;
    queue<pair<int, int>> Q;
    Q.push({tomX, tomY});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int x = cur.first;
        int y = cur.second;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            while (1) {
                if (nx < 1 || ny < 1 || nx > n || ny > n || board[nx][ny] == 1) break;
                if (board[nx][ny] == -1) {
                    board[nx][ny] = board[x][y] + 1;
                    Q.push({nx, ny});
                }
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
    if (board[jerryX][jerryY] == -1) {
        cout << -1;
    } else {
        cout << board[jerryX][jerryY] - 1;
    }
}