#include "bits/stdc++.h"

using namespace std;

int iceberg[305][305];
bool visited[305][305];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


void init(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visited[i][j] = false;
        }
    }
}


void dfs(int x, int y) {
    int melting = 4;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (iceberg[nx][ny] > 0) {
            melting -= 1;
        }
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!visited[nx][ny] && iceberg[nx][ny] > 0) {
            visited[nx][ny] = true;
            dfs(nx, ny);
        }
    }
    iceberg[x][y] -= melting;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> iceberg[i][j];
        }
    }
    while (1) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (iceberg[i][j] > 0 && !visited[i][j]) {
                    visited[i][j] = true;
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        if (cnt > 1) {
            break;
        }
        if (cnt == 0) {
            cout << 0;
            return 0;
        }
        init(n, m);
        ans++;
    }
    cout << ans;
}