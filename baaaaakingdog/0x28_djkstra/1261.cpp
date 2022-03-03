#include "bits/stdc++.h"

#define INF 2147000

using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int d[101][101];
int board[101][101];


void solve(int h, int w) {
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    d[0][0] = 0;
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (board[nx][ny] == 1 && d[nx][ny] > d[x][y]+1) {
                d[nx][ny] = d[x][y] + 1;
                Q.push({nx, ny});
            } else if (board[nx][ny] == 0 && d[nx][ny] > d[x][y]) {
                d[nx][ny] = d[x][y];
                Q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int w, h;
    cin >> w >> h;
    for (int i = 0; i < h; ++i) {
        string input;
        cin >> input;
        for (int j = 0; j < input.length(); ++j) {
            board[i][j] = input[j] - '0';
            d[i][j] = INF;
        }
    }
    solve(h, w);
    cout << d[h - 1][w - 1];
}