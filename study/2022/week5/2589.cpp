#include "bits/stdc++.h"

using namespace std;
char t_map[51][51];
int board[51][51];
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int bfs(int x, int y) {
    queue<pair<int, int >> Q;
    Q.push({x, y});
    board[x][y] = 0;
    int last = 0;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        last = board[cur.first][cur.second];
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (t_map[nx][ny] == 'L' && board[nx][ny] == -1) {
                board[nx][ny] = board[cur.first][cur.second] + 1;
                Q.push({nx, ny});
            }
        }
    }
    return last;
}
void init() {
    for (int i = 0; i < n; ++i) {
        fill(board[i], board[i] + m, -1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int answer = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> t_map[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (t_map[i][j] == 'L') {
                if (j - 1 >= 0 && j + 1 < m && t_map[i][j - 1] == 'L' && t_map[i][j + 1] == 'L') continue;
                if (i - 1 >= 0 && i + 1 < n && t_map[i - 1][j] == 'L' && t_map[i + 1][j] == 'L') continue;
                init();
                answer = max(answer, bfs(i, j));
            }
        }
    }
    cout << answer;

}