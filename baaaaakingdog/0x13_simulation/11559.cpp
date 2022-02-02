#include "bits/stdc++.h"

using namespace std;

char puyo[12][6];
bool visited[12][6];
int board[12][6];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(int x, int y, char pu) {
    int cnt = 1;
    board[x][y] = -2;
    visited[x][y] = true;
    queue<pair<int, int >> Q;
    Q.push({x, y});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
            if (puyo[nx][ny] == pu && !visited[nx][ny]) {
                board[nx][ny] = -2;
                cnt++;
                visited[nx][ny] = true;
                Q.push({nx, ny});
            }
        }
    }
    return cnt;
}

void bomb() {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 6; ++j) {
            if(board[i][j] == -2) {
                puyo[i][j] = '.';
            }
        }
    }
}

void init () {
    for (int i = 0; i < 12; ++i) {
        fill(visited[i], visited[i] + 6, false);
        fill(board[i], board[i] + 6, 0);
    }
}

void fall(int x,  int y ){
    if(x==11 || puyo[x+1][y] != '.') {
        return;
    }
    char tmp = puyo[x][y];
    int tmp_x = x;
    int tmp_y = y;
    while (true) {
        x++;
        if(x==11 || puyo[x+1][y] != '.'){
            break;
        }
    }
    puyo[x][y] = tmp;
    puyo[tmp_x][tmp_y] = '.';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 12; ++i) {
        cin >> puyo[i];
    }
    int ans = 0;
    while (1) {
        bool flag = true;
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (puyo[i][j] != '.'){
                    init();
                    int cnt = bfs(i,j,puyo[i][j]);
                    if (cnt >= 4) {
                        flag = false;
                        bomb();
                    }
                }
            }
        }
        for (int i = 11; i >=0; --i) {
            for (int j = 0; j < 6; ++j) {
               if(puyo[i][j] != '.'){
                   fall(i,j);
               }
            }
        }

        if (flag) break;
        ans++;
    }
    cout << ans;
}