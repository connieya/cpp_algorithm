#include "bits/stdc++.h"

using namespace std;

int grass[31][31];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> Q;


bool isFullOfGrass(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grass[i][j] == 0) return false;
        }
    }
    return true;
}


void bfs(int n) {
    int len = Q.size();
    for (int i = 0; i < len; ++i) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int j = 0; j < 4; ++j) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                continue;
            }
            if (grass[nx][ny] == 0) {
                grass[nx][ny] = 2;
                Q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grass[i][j];
            if (grass[i][j] == 2) {
                Q.push({i, j});
            }
        }
    }
    int t = 0;
    while (!isFullOfGrass(n)) {
        bfs(n);
        t++;
    }
    cout << t;

}