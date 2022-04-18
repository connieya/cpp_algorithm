#include "bits/stdc++.h"

using namespace std;

char board[51][51];
int visited[51][51];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void print_res(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << '\n';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> Q;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); ++j) {
            board[i][j] = str[j];
            visited[i][j] = -1;
            if (board[i][j] == '*') {
                Q.push({i, j});
                visited[i][j] = 0;
            }
        }
    }
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == '.' && visited[nx][ny] == -1) {
                visited[nx][ny] = visited[x][y] + 1;
                Q.push({nx, ny});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'S') {
                Q.push({i, j});
                visited[i][j] = 0;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (board[nx][ny] == 'D') {
                cout << visited[x][y] + 1 << '\n';
                exit(0);
            }
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == '.' && (visited[nx][ny] == -1 || visited[nx][ny] > visited[x][y] + 1)) {
                Q.push({nx, ny});
                visited[nx][ny] = visited[x][y] + 1;
            }
        }
    }

    cout << "KAKTUS";

}