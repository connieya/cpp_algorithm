﻿#include "bits/stdc++.h"

using namespace std;

struct cross {
    int x;
    int y;
    int size;
};

int n, m;
char board[102][102];
bool check[102][102];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<cross> ans;

bool OOP(int x, int y) {
    return x < 1 || x > n || y < 1 || y > m;
}

int getCrossSize(int x, int y) {
    int mn = INT_MAX;
    for (int i = 0; i < 4; ++i) {
        int nx = x;
        int ny = y;
        int cnt = 0;
        while (1) {
            nx += dx[i];
            ny += dy[i];
            if (OOP(nx, ny) || board[nx][ny] != '*') break;
            cnt++;
        }
        mn = min(mn, cnt);
    }
    return mn;
}

void checkCross(int x, int y) {
    int cnt = getCrossSize(x, y);
//    cout << x << ' ' << y << ' ' << cnt << '\n';
    if (!cnt) return;
    check[x][y] = 1;
    for (int i = 1; i <= cnt; ++i) {
        ans.push_back({x, y, i});
        check[x + i][y] = 1;
        check[x][y + i] = 1;
        check[x - i][y] = 1;
        check[x][y - i] = 1;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> board[i][j];
        }
    }


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (board[i][j] == '*') {
                checkCross(i, j);
            }
        }
    }


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (board[i][j] == '*' && !check[i][j]) {
                cout << -1;
                exit(0);
            }
        }

    }


    cout << ans.size() << '\n';
    for (auto a: ans) {
        cout << a.x << ' ' << a.y << ' ' << a.size << '\n';
    }

}