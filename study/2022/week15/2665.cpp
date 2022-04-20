#include "bits/stdc++.h"

using namespace std;

char maze[51][51];
bool visited[51][51];
bool spareList[51][51];
vector<pair<int, int>> spare;

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
            cin >> maze[i][j];
        }
    }
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (!visited[nx][ny]) {
                if (maze[nx][ny] == '1') {
                    Q.push({nx,ny});
                    visited[nx][ny] = true;
                } else if (maze[nx][ny] == '0' && !spareList[nx][ny]) {
                    spare.push_back({nx, ny});
                    spareList[nx][ny] = true;

                }
            }
        }

    }
}