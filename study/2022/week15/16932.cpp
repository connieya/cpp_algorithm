#include "bits/stdc++.h"

using namespace std;

int board[1001][1001];
bool visited[1001][1001];
vector<pair<int,int>> point;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;

int bfs(int x, int y) {
    int shape_size = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!visited[nx][ny] && board[nx][ny] == 1) {
                visited[nx][ny] = true;
                shape_size++;
                q.push({nx, ny});
            }
        }
    }
    return shape_size;
}

int maxShapeSize() {
    int maxShape = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 1 && !visited[i][j]) {
                int cnt = bfs(i, j);
                maxShape = max(cnt, maxShape);
            }
        }
    }
    return maxShape;
}

void init() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visited[i][j] = false;
        }
    }
}

int solve() {
    int ans = -1;
    int len = point.size();
    for (int i = 0; i < len; ++i) {
        int x = point[i].first;
        int y = point[i].second;
        board[x][y] = 1;
        int m = maxShapeSize();
        board[x][y] = 0;
        init();
        ans = max(ans,m);
    }
    return ans;
}

int calc(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (board[nx][ny] == 1) cnt++;
    }
    return cnt;
}

void ps() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 0 && calc(i,j) > 1){
                point.push_back({i,j});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    ps();
    cout << solve();

}