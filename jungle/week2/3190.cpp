#include "bits/stdc++.h"

using namespace std;

typedef struct snake {
    int x;
    int y;

    snake(int i, int j) {
        x = i;
        y = j;
    }
} Snake;

int board[105][105];
int turn[10001];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
queue<Snake> DummyGame;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, l, second, dir = 0;
    char turnabout;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        board[a][b] = 7;
    }
    cin >> l;
    for (int i = 0; i < l; ++i) {
        cin >> second >> turnabout;
        if (turnabout == 'D') {
            turn[second] = 1;
        } else {
            turn[second] = -1;
        }
    }
    int x = 1, y = 1, time = 0;
    DummyGame.push(Snake(x, y));
    board[x][y] = -1;
    while (true) {
        if (turn[time] == 1) {
            dir = (dir + 1) % 4;
        } else if (turn[time] == -1) {
            dir = (dir + 3) % 4;
        }
        x += dx[dir];
        y += dy[dir];
        DummyGame.push(Snake(x, y));
        time++;
        if (x < 1 || y < 1 || x > n || y > n || board[x][y] == -1) {
            cout << time;
            exit(0);
        }
        if (board[x][y] != 7) {
            int i = DummyGame.front().x;
            int j = DummyGame.front().y;
            board[i][j] = 0;
            DummyGame.pop();
        }
        board[x][y] = -1;
    }

}