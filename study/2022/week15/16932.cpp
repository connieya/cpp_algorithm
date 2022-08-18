#include "bits/stdc++.h"

using namespace std;

int n, m;
int board[1005][1005];
bool visited[1005][1005];
unordered_map<int, int> mp;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(int x, int y, int num) {
    int count = 1;
    queue<pair<int, int>> q;
    board[x][y] = num;
    visited[x][y] = 1;
    q.push({x, y});
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || !board[nx][ny]) continue;
            if (!visited[nx][ny]) {
                visited[nx][ny] = 1;
                count++;
                board[nx][ny] = num;
                q.push({nx, ny});
            }
        }
    }
    return count;
}

int solve(int x, int y) {
    int sum = 0;
    unordered_map<int,bool> check;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (board[nx][ny] && !check[board[nx][ny]]) {
            sum += mp[board[nx][ny]];
            check[board[nx][ny]] = 1;
        }
    }
    return sum;
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
    int num = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] && !visited[i][j]) {
                int cnt = bfs(i, j, num);
                mp[num] = cnt;
                num++;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j]) continue;
            int sum = solve(i, j);
            if (++sum > res) {
                res = sum;
            }
        }
    }
//    for (auto m: mp) {
//        cout << m.first << ' ' << m.second << '\n';
//    }
    cout << res;
}