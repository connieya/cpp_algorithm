#include "bits/stdc++.h"

using namespace std;

int arr[250][250];

int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
int n, m;

void bfs(int x, int y) {
    arr[x][y] = 0;
    queue<pair<int, int>> Q;
    Q.push({x, y});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 8; ++i) {
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (arr[nx][ny] == 1){
                Q.push({nx,ny});
                arr[nx][ny] = 0;
            }

        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == 1) {
                ans++;
                bfs(i, j);
            }
        }
    }
    cout << ans;

}