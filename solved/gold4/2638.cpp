#include "bits/stdc++.h"

using namespace std;

int cheese[101][101];
int check[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;

void init() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            check[i][j] = 0;
        }
    }

}

void bfs() {
    init();
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    check[0][0] = -1;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int x = cur.first;
        int y = cur.second;
        for (int i = 0; i < 4; ++i) {
            int nx = dx[i]+x;
            int ny = dy[i]+y;
            if (nx < 0 || nx >=n || ny < 0 || ny >=m) continue;
            if (cheese[nx][ny] == 0 && check[nx][ny] != -1){
                check[nx][ny] = -1;
                Q.push({nx,ny});
            }
            if (cheese[nx][ny] == 1){
                check[nx][ny]++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (check[i][j] >=2)  cheese[i][j] = 0;
        }
    }

}

void print() {
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << check[i][j] << ' ';
        }
        cout << '\n';

    }
    cout << "***************************************8" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> cheese[i][j];
        }
    }
    int ans = 0;
    while (1) {
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (cheese[i][j]) {
                    flag = false;
                }
            }
            if (!flag) break;
        }
        if (flag) break;
        ans++;
        bfs();
    }
    cout << ans;
}