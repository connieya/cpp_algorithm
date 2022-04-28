#include "bits/stdc++.h"

using namespace std;

int n;
int arr[501][501];
int visited[501][501];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


void init() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            visited[i][j] = -1;
        }
    }
}

int dfs(int x, int y) {
    if (visited[x][y] == -1) {
        visited[x][y] = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >=n || ny < 0 || ny >=n ) continue;
            if (arr[nx][ny] > arr[x][y]) {
                visited[x][y] = max(visited[x][y] , dfs(nx,ny));
            }
        }
    }
    return visited[x][y]+1;
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
    init();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans;
}