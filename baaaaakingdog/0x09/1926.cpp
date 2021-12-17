#include "bits/stdc++.h"

int board[502][502];
bool visit[502][502];
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int countWidth(int x, int y, int n, int m);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int cnt = 0, mx = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] && !visit[i][j]) {
                cnt++;
                visit[i][j] = true;
                mx = max(mx, countWidth(i, j, n, m));
            }
        }
    }
    cout << cnt << '\n' << mx;
}

int countWidth(int x, int y, int n, int m) {
    int width = 1;
    queue<pair<int, int>> queue;
    queue.push({x, y});
    while (!queue.empty()) {
        auto cur = queue.front();
        queue.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = dx[k] + cur.first;
            int ny = dy[k] + cur.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny]&& board[nx][ny]) {
                visit[nx][ny] = 1;
                width++;
                queue.push({nx, ny});
            }
        }
    }
    return width;
}

