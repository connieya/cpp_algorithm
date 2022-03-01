#include "bits/stdc++.h"

using namespace std;

int chess[201][201];
int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};
int n ,a2,b2;

void init(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            chess[i][j] = -1;
        }
    }
}

int bfs(int a, int b) {
    chess[a][b] = 0;
    queue<pair<int, int>> q;
    q.push({a,b});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        if (x==a2 && y == b2) return chess[a2][b2];
        q.pop();
        for (int i = 0; i < 6; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >=n || ny < 0 || ny >= n) continue;
            if (chess[nx][ny] == -1) {
                chess[nx][ny] = chess[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    return chess[a2][b2];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    init(n);
    int a1, b1;
    cin >> a1 >> b1 >> a2 >> b2;
    cout << bfs(a1,b1);
}