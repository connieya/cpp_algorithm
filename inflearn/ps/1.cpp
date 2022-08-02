﻿#include "bits/stdc++.h"

using namespace std;

int n, tx, ty, zx, zy;
int board[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    cin >> tx >> ty >> zx >> zy;
    queue<pair<int, int>> q;
    q.push({tx - 1, ty - 1});
    board[tx - 1][ty - 1] = 2;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            while (nx >= 0 && nx < n && ny >=0 && ny < n && board[nx][ny] != 1){
                if(board[nx][ny] == 0) {
                    q.push({nx,ny});
                    board[nx][ny] = board[x][y] +1;
                }
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
    cout << (board[zx-1][zy-1] ? board[zx-1][zy-1]-3 : -1);
}