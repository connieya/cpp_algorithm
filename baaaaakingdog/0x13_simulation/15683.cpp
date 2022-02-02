#include "bits/stdc++.h"

#define X first
#define Y second
using namespace std;

int n, m;
int office[10][10];
int board[10][10];
vector<pair<int, int>> cctv;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool OOB(int a, int b) {
    return a < 0 || a >= n || b < 0 || b >= m;
}

void upd(int x, int y, int dir) {
    dir %= 4;
    while (1) {
        x += dx[dir];
        y += dy[dir];
        if (OOB(x, y) || board[x][y] == 6) {
            return;
        }
        if (board[x][y] != 0) continue;
        board[x][y] = 7;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> office[i][j];
            if (office[i][j] != 0 && office[i][j] != 6) {
                cctv.push_back({i, j});
            }
            if (office[i][j] == 0) ans++;
        }
    }
    for (int temp = 0; temp < 1 << (2 * cctv.size()); ++temp) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                board[i][j] = office[i][j];
            }
        }
        int brute = temp;
        for (int i = 0; i < cctv.size(); ++i) {
            int dir = brute % 4;
            brute /= 4;
            int x = cctv[i].X;
            int y = cctv[i].Y;
            if (office[x][y] == 1) {
                upd(x, y, dir);
            }
            if (office[x][y] == 2) {
                upd(x, y, dir);
                upd(x, y, dir + 2);
            }
            if (office[x][y] == 3) {
                upd(x, y, dir);
                upd(x, y, dir + 1);

            }
            if (office[x][y] == 4) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);

            }
            if (office[x][y] == 5){
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
                upd(x, y, dir + 3);

            }
            int val = 0;
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < m; ++k) {
                    val += (board[j][k] == 0);
                }
            }
            ans = min(ans, val);
        }
    }
    cout << ans;
}