#include "bits/stdc++.h"

using namespace std;
int n, m;
int group_num = 1;
int group_size[300001];
int board[1001][1001];
bool group_check[300001];
bool visited[1001][1001];
vector<pair<int, int>> point;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int makeGroup(int x, int y) {
    int group_size = 1;
    board[x][y] = group_num;
    queue<pair<int, int>> Q;
    visited[x][y] = true;
    Q.push({x, y});
    while (!Q.empty()) {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                board[nx][ny] = group_num;
                group_size++;
                Q.push({nx, ny});
            }
        }
    }
    return group_size;
}

int maxShapeSize(int x, int y) {
    int size = 0;
    int g;
    vector<pair<int,int>> v;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        g = board[nx][ny];
        v.push_back({nx,ny});
        if (!group_check[g]) {
            group_check[g] = true;
            size += group_size[board[nx][ny]];
        }
    }
    for (auto i : v){
        x = i.first;
        y = i.second;
        group_check[board[x][y]] = false;
    }
    return size;
}

int solve() {
    int len = point.size();
    int ans = -1;
    for (int i = 0; i < len; ++i) {
        int x = point[i].first;
        int y = point[i].second;
//        cout << "X : " << x << " Y  : " << y;
        int cnt = maxShapeSize(x, y);
//        cout << "  size =>> " << cnt << '\n';
        ans = max(ans, cnt);
    }
    return ans + 1;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                point.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 1 && !visited[i][j]) {
                group_size[group_num] = makeGroup(i, j);
                group_num++;
            }
        }
    }
    cout << solve();

}