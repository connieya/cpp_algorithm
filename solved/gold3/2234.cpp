#include "bits/stdc++.h"

using namespace std;

int board[51][51];
bool visited[51][51];
int r[51][51];
string info[51][51];
int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(int x, int y, int num) {
    queue<pair<int, int>> q;
    q.push({x, y});
    r[x][y] = num;
    int cnt = 1;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            string str = info[x][y];
            if (str[i] == '1') continue;
            if (r[nx][ny] == -1) {
                r[nx][ny] = num;
                q.push({nx, ny});
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            int n = board[i][j];
            string tmp = "";
            while (n) {
                tmp += to_string(n % 2);
                n /= 2;
            }
            while (tmp.size() < 4) {
                tmp += '0';
            }
            reverse(tmp.begin(), tmp.end());
            info[i][j] = tmp;
        }
    }
    memset(r, -1, sizeof(r));
    unordered_map<int, int> rooms;
    int a1, a2 = 0, a3 = 0;
    int num = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (r[i][j] == -1) {
                int res = bfs(i, j, num);
                if (res > a2) a2 = res;
                rooms[num] = res;
                num++;
            }
        }
    }

    a1 = rooms.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            string str = info[i][j];
            for (int k = 0; k < 4; ++k) {
                int nx = dx[k] + i;
                int ny = dy[k] + j;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (str[k] == '1' && r[i][j] != r[nx][ny]) {
                    int sum = rooms[r[i][j]] + rooms[r[nx][ny]];
                    if (sum > a3) a3 = sum;
                }
            }
        }
    }
    cout << a1 << '\n' << a2 << '\n' << a3 << '\n';
}