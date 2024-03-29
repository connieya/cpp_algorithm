﻿#include "bits/stdc++.h"

using namespace std;

int n, m, t;
int board[51][51];
int temp[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
pair<int, int> air;

void spread(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == -1) continue;
        temp[nx][ny] += board[x][y] / 5;
    }
}

void remain(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == -1) continue;
        cnt++;
    }
    board[x][y] -= ((board[x][y] / 5 )* cnt);
}

void blow(){
    // 위쪽 공기 청정기
    for (int i = air.first-1; i  > 0; --i) {
        board[i][0] = board[i-1][0];
    }
    for (int i = 0; i < m-1; ++i) {
        board[0][i] = board[0][i+1];
    }
    for (int i = 0; i < air.first; ++i) {
        board[i][m-1] = board[i+1][m-1];
    }
    for (int i = m-1; i  > 1 ; --i) {
        board[air.first][i] = board[air.first][i-1];
    }
    board[air.first][1] = 0;

    // 아래쪽 공기 청정기
    for (int i = air.second+1; i < n; ++i) {
        board[i][0] = board[i+1][0];
    }
    for (int i = 0; i < m-1; ++i) {
        board[n-1][i] = board[n-1][i+1];
    }
    for (int i = n-1; i > air.second ; --i) {
        board[i][m-1] = board[i-1][m-1];
    }
    for (int i = m-1; i > 1; --i) {
        board[air.second][i] = board[air.second][i-1];
    }
    board[air.second][1] = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            if (board[i][j] == -1) air.second = i;
        }
    }
    air.first = air.second - 1;
    while (t--) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] > 0) {
                    spread(i, j);
                    remain(i, j);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == -1) continue;
                board[i][j] += temp[i][j];
                temp[i][j] = 0;
            }
        }
        blow();
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans += board[i][j];
        }
    }
    cout << ans + 2;

}