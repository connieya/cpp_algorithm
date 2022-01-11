#include "bits/stdc++.h"

using namespace std;

int R, C;
char pasture[502][502];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C;
    queue<pair<int, int>> Q;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> pasture[i][j];
            if (pasture[i][j] == 'W') {
                Q.push({i, j});
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
            if (pasture[nx][ny] == 'S') {
                cout << 0 << '\n';
                return 0;
            } else if (pasture[nx][ny] == '.') {
                pasture[nx][ny] = 'D';
            }
        }
    }
    cout << 1 << '\n';
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << pasture[i][j];
        }
        cout << '\n';
    }
}

