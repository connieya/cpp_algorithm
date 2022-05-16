#include "bits/stdc++.h"

using namespace std;

int r, c;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char board[11][11];

void check(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c || board[nx][ny] == '.') {
            cnt++;
        }
    }
    if (cnt >= 3) board[x][y] = '^';
}

void func() {
    pair<int, int> x;
    pair<int, int> y;
    x.first = y.first = INT_MAX;
    x.second = y.second = INT_MIN;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (board[i][j] == 'X') {
                x.first = min(i,x.first);
                x.second = max(i,x.second);
                y.first = min(j,y.first);
                y.second = max(j,y.second);
            }else {
                board[i][j] = '.';
            }
        }
    }

    for (int i = x.first; i <= x.second; ++i) {
        for (int j = y.first; j <= y.second; ++j) {
            cout << board[i][j];
        }
        cout <<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        cin >> board[i];
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (board[i][j] == 'X') {
                check(i, j);
            }
        }
    }
    func();
}