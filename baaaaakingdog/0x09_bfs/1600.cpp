#include "bits/stdc++.h"

using namespace std;

struct Info {
    int x, y, cnt;
};


int k, w, h;
int board[201][201];
int dp[201][201][31];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int cx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int cy[] = {-2, -1, 1, 2, 2, 1, -1, -2};


void bfs() {
    dp[0][0][0] = 0;
    queue<Info> Q;
    Q.push({0, 0, 0});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int cnt = cur.cnt;
        int x = cur.x;
        int y = cur.y;
        if (x == h - 1 && y == w - 1) {
            cout << dp[x][y][cnt];
            exit(0);
        }
        if (cnt < k) {
            for (int i = 0; i < 8; ++i) {
                int nx = x + cx[i];
                int ny = y + cy[i];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (dp[nx][ny][cnt+1] == -1 && board[nx][ny] == 0) {
                    dp[nx][ny][cnt + 1] = dp[x][y][cnt] + 1;
                    Q.push({nx, ny, cnt + 1});
                }
            }
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (dp[nx][ny][cnt] == -1 && board[nx][ny] == 0) {
                dp[nx][ny][cnt] = dp[x][y][cnt] + 1;
                Q.push({nx, ny, cnt});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> w >> h;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> board[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    bfs();
    cout << -1 << '\n';
}