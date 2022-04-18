#include "bits/stdc++.h"

using namespace std;

char miro[51][51];
int visited[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); ++j) {
            miro[i][j] = str[j];
            visited[i][j] = INT_MAX;
        }
    }
    queue<pair<int, int>> Q;
    visited[0][0] = 0;
    Q.push({0, 0});
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (miro[nx][ny] == '1') {
                if (visited[nx][ny] > visited[x][y]) {
                    visited[nx][ny] = visited[x][y];
                    Q.push({nx, ny});
                }
            } else {
                if (visited[nx][ny] > visited[x][y] + 1) {
                    visited[nx][ny] = visited[x][y] + 1;
                    Q.push({nx, ny});
                }
            }

        }
    }
    cout << visited[n - 1][n - 1];
}