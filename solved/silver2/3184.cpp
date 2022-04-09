#include "bits/stdc++.h"

using namespace std;

char yard[251][251];
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int animal[2];

void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    int sheep = 0, wolf = 0;
    if (yard[x][y] == 'o') {
        sheep++;
    } else if (yard[x][y] == 'v') {
        wolf++;
    }
    yard[x][y] = '#';
    Q.push({x, y});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (yard[nx][ny] != '#') {
                if (yard[nx][ny] == 'o') {
                    sheep++;
                } else if (yard[nx][ny] == 'v') {
                    wolf++;
                }
                yard[nx][ny] = '#';
                Q.push({nx, ny});
            }
        }
    }
    if (sheep > wolf) {
        animal[0] += sheep;
    } else {
        animal[1] += wolf;
    }



}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> yard[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (yard[i][j] == 'o' || yard[i][j] == 'v') {
                bfs(i, j);
            }
        }
    }
    cout << animal[0] << ' ' << animal[1];
}