#include "bits/stdc++.h"

using namespace std;

char f_map[51][51];
int board[51][51];
int R, C;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void init() {
    for (int i = 0; i < R; ++i) {
        fill(board[i], board[i] + C, -1);
    }
}

int bfs_g(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    board[x][y] = 0;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (f_map[nx][ny] == 'D') {
                return board[cur.first][cur.second] + 1;
            }
            if (f_map[nx][ny] == '.' && (board[nx][ny] == -1 || board[cur.first][cur.second] + 1 < board[nx][ny])) {
                board[nx][ny] = board[cur.first][cur.second] + 1;
                Q.push({nx, ny});
            }
        }
    }
    return -1;
}

void solve_w() {
    init();
    queue<pair<int, int>> Q;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (f_map[i][j] == '*') {
                Q.push({i, j});
                board[i][j] = 0;
            }
        }
    }
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (f_map[nx][ny] == 'X' || f_map[nx][ny] == 'D') continue;
            if (f_map[nx][ny] == '.' && board[nx][ny] == -1) {
                board[nx][ny] = board[cur.first][cur.second] + 1;
                Q.push({nx, ny});
            }
        }
    }
}

int solve_g() {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (f_map[i][j] == 'S') {
                return bfs_g(i, j);

            }
        }
    }
    return -1;
}

void test() {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        cin >> f_map[i];
    }
    solve_w();
    int res = solve_g();
    if (res == -1) {
        cout << "KAKTUS";
    } else {
        cout << res;
    }
}