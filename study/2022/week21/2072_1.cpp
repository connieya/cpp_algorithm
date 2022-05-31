#include "bits/stdc++.h"

using namespace std;

int board[20][20];
int dx[] = {1, 0, 1, -1};
int dy[] = {0, 1, 1, 1};


int recur(int x, int y, int nx, int ny, int color) {
    if (x >= 20 || x < 1 || y >= 20 || y < 1) return 0;

    if (board[x][y] == color) {
        return 1 + recur(x + nx, y + ny, nx, ny, color);
    }
    return 0;
}

bool isGameOver(int x, int y, int color) {
    for (int i = 0; i < 4; ++i) {
        int cnt = recur(x + dx[i], y + dy[i], dx[i], dy[i], color);
        cnt += recur(x - dx[i], y - dy[i], -dx[i], -dy[i], color);
        if (cnt + 1 == 5) return true;
    }
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