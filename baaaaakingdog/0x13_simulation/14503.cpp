#include "bits/stdc++.h"

using namespace std;

int n, m, dir, r, c, ans = 1;
int room[51][51];
int board[51][51];

int dx[] = {-1, 0, 1, 0}; // 북 , 동 , 남 ,서
int dy[] = {0, 1, 0, -1};

void rotate() {
    dir--;
    if (dir == -1) {
        dir = 3;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> r >> c >> dir;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> room[i][j];
        }
    }
    queue<pair<int, int>> q;
    q.push({r, c});
    board[r][c] = 1;
    int turn = 0;
    while (true) {
        rotate();
        int nx = r + dx[dir];
        int ny = c + dy[dir];
        turn++;
        if (room[nx][ny] == 0 && board[nx][ny] == 0) {
            board[nx][ny] = 1;
            ans++;
            turn = 0;
            r = nx;
            c = ny;
            continue;
        }
        if (turn == 4) {
            nx = r - dx[dir];
            ny = c - dy[dir];
            if (room[nx][ny] == 0) {
                r = nx;
                c = ny;
                turn = 0;
            } else {
                break;
            }
        }
    }
    cout << ans;
}