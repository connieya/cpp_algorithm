#include "bits/stdc++.h"

using namespace std;

struct Robot {
    int x, y, dir;
};


int n, m, x, y;
Robot R[105];
int dx[] = {0, 1, 0, -1}; // N , E , S , W
int dy[] = {1, 0, -1, 0}; // 0  1  2  3
int board[105][105];

bool OOP(int x, int y) {
    return x < 1 || x > n || y < 1 || y > m;
}

void solve(int number, char command, int cnt) {
    struct Robot robot = R[number];
    int x = robot.x;
    int y = robot.y;
    int dir = robot.dir;
    if (command == 'F') {
        board[x][y] = 0;
        while (cnt--) {
            x += dx[dir];
            y += dy[dir];
            if (OOP(x, y)) {
                cout << "Robot " << number << " crashes into the wall";
                exit(0);
            }
            if (board[x][y]) {
                cout << "Robot " << number << " crashes into robot " << board[x][y];
                exit(0);
            }
        }
        board[x][y] = number;
        R[number].x = x;
        R[number].y = y;
    } else if (command == 'R') {
        while (cnt--) {
            dir = (dir + 1) % 4;
        }
        R[number].dir = dir;
    } else {
        while (cnt--) {
            dir--;
            dir = dir < 0 ? 3 : dir;
        }
        R[number].dir = dir;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x >> y;
    int a, b, number, cnt, n;
    char dir, command;
    const string direction = "NESW";
    for (int i = 1; i <= x; ++i) {
        cin >> a >> b >> dir;
        n = direction.find(dir);
        R[i] = {a, b, n};
        board[a][b] = i;
    }
    for (int i = 0; i < y; ++i) {
        cin >> number >> command >> cnt;
        solve(number, command, cnt);
    }
    cout << "OK";
}