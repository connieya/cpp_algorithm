#include "bits/stdc++.h"

using namespace std;

int n, m, k;
char board[1001][1001];
int ans[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    int x1, y1, x2, y2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            ans[i][j] = -1;
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;
    queue<pair<int, int>> q;
    q.push({x1 - 1, y1 - 1});
    ans[x1 - 1][y1 - 1] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int cnt = 0;
            while (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == '.' && cnt < k) {
                if (ans[nx][ny] == -1) {
                    q.push({nx, ny});
                    ans[nx][ny] = ans[x][y] + 1;
                }
                if(nx == x2-1 && ny == y2-1 || ans[nx][ny] < ans[x][y]+1) break;
                nx += dx[i];
                ny += dy[i];
                cnt++;
            }
        }
    }
    cout << (ans[x2 - 1][y2 - 1] == -1 ? -1 : ans[x2 - 1][y2 - 1]);
}