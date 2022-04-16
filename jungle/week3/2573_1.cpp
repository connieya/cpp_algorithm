#include "bits/stdc++.h"

using namespace std;
int N, M;
int ice[301][301];
bool visited[301][301];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    visited[x][y] = true;
    while (!Q.empty()) {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (visited[nx][ny]) continue;
            if (ice[nx][ny] <=0){
                ice[x][y] -=1;
            }else {
                visited[nx][ny] = true;
                Q.push({nx,ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> ice[i][j];
        }
    }
    int t = 0;
    while (true) {
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (ice[i][j] > 0 && !visited[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        if (cnt == 0) {
            cout << 0;
            return 0;
        }
        if (cnt > 1) {
            break;
        }
        t++;
    }
    cout << t;
}