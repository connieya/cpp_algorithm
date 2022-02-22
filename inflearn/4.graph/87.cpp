#include "bits/stdc++.h"

using namespace std;

int arr[21][21];
int n;

int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

void bfs(int x, int y) {
    arr[x][y] = 0;
    queue<pair<int, int>> Q;
    Q.push({x, y});
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >=n || ny < 0 || ny >= n) continue;
            if (arr[nx][ny] == 1){
                arr[nx][ny] = 0;
                Q.push({nx,ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == 1) {
                ans++;
                bfs(i, j);
            }
        }
    }
    cout << ans;


}