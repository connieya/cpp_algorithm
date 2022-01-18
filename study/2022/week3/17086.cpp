#include "bits/stdc++.h"

using namespace std;

int board[51][51];
int n,m;
int dx[] = {-1,0,1,0 ,-1,-1,1,1};
int dy[] = {0,1,0,-1,-1,1,1,-1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    queue<pair<int ,int >> Q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                Q.push({i,j});
            }
        }
    }
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 8; ++i) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;
            if (nx < 0 || nx >= n || ny <0 || ny >= m) continue;
            if (board[nx][ny] == 0) {
                board[nx][ny] = board[cur.first][cur.second]+1;
                Q.push({nx,ny});
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans = max(ans , board[i][j]);
        }
    }
    cout << ans-1;
}