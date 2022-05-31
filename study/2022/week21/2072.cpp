#include "bits/stdc++.h"

using namespace std;

int board[20][20];

int recur_horizon(int x, int y, int color) {
    int cnt = 1;
    int ny = y;
    while (++y <= 19) {
        if (board[x][y] == color) cnt++;
        else break;
    }
    while (--ny >= 1) {
        if (board[x][ny] == color) cnt++;
        else break;
    }
    return cnt;
}

int recur_vertical(int x, int y, int color) {
    int cnt = 1;
    int nx = x;

    while (--x >= 1) {
        if (board[x][y] == color) cnt++;
        else break;
    }

    while (++nx <= 19) {
        if (board[nx][y] == color) cnt++;
        else break;
    }
    return cnt;
}

int recur_left_diagonal(int x, int y, int color) {
    int cnt = 1;
    int nx = x;
    int ny = y;
    while (--x >= 1 && --y >= 1) {
        if (board[x][y] == color) cnt++;
        else break;
    }

    while (++nx <= 19 && ++ny <= 19) {
        if (board[nx][ny] == color) cnt++;
        else break;
    }
}

int recur_right_diagonal(int x, int y, int color) {
    int cnt = 1;
    int nx = x;
    int ny = y;
    while (--x >= 1 && ++y <= 19) {
        if (board[x][y] == color) cnt++;
        else break;
    }

    while (++nx <= 19 && --ny >= 1) {
        if (board[nx][ny] == color) cnt++;
        else break;
    }
    return cnt;
}

bool isGameOver(int x, int y, int color) {
    int res = recur_horizon(x, y, color);
    if (res == 5) return true;
    res = recur_left_diagonal(x, y, color);
    if (res == 5) return true;
    res = recur_right_diagonal(x, y, color);
    if (res == 5) return true;
    res = recur_vertical(x, y, color);
    if (res == 5) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        if (isGameOver(x, y, i % 2 + 1)) {
            cout << i;
            exit(0);
        }
        board[x][y] = i % 2 + 1; // 1 or 2
    }
    cout << -1;
}