#include "bits/stdc++.h"

using namespace std;

int board[9][9];
bool check[9][9];
int n, m;
vector<pair<int, int>> cctv;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int d[9];
int idx[] = {0, 4, 2, 4, 4, 1};

void f(int x, int y, int dir) {
    int nx = x;
    int ny = y;
    check[x][y] = 1;
    while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (board[nx][ny] == 6) break;
        nx += dx[dir];
        ny += dy[dir];
        check[nx][ny] = 1;
    }
}

int dfs(int L) {
    if (L == cctv.size()) {
        for (int i = 0; i < cctv.size(); ++i) {
            int num = board[cctv[i].first][cctv[i].second];
            if (num == 1) {
                f(cctv[i].first, cctv[i].second, (d[i] + 1) % 4);
            } else if (num == 2) {
                f(cctv[i].first, cctv[i].second, (d[i] + 1) % 4);
                f(cctv[i].first, cctv[i].second, (d[i] + 3) % 4);
            } else if (num == 3) {
                f(cctv[i].first, cctv[i].second, d[i]);
                f(cctv[i].first, cctv[i].second, (d[i] + 1) % 4);
            } else if (num == 4) {
                f(cctv[i].first, cctv[i].second, d[i]);
                f(cctv[i].first, cctv[i].second, (d[i] + 1) % 4);
                f(cctv[i].first, cctv[i].second, (d[i] + 3) % 4);
            } else {
                f(cctv[i].first, cctv[i].second, 0);
                f(cctv[i].first, cctv[i].second, 1);
                f(cctv[i].first, cctv[i].second, 2);
                f(cctv[i].first, cctv[i].second, 3);
            }

        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 6) continue;
                cnt += (check[i][j] == 0);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                check[i][j] = 0;
            }
        }
        return cnt;
    }
    int num = board[cctv[L].first][cctv[L].second];
    int ans = 100;
    for (int i = 0; i < idx[num]; ++i) {
        d[L] = i;
        int temp = dfs(L + 1);
        if (ans > temp) ans = temp;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            if (board[i][j] && board[i][j] != 6) {
                cctv.push_back({i, j});
            }
        }
    }
    cout << dfs(0);
}