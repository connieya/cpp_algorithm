#include "bits/stdc++.h"

using namespace std;

int grass[31][31];
int board[31][31];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> Q;
int bfs(int n) {
    int res = 0;
    while (!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >=n || ny < 0 || ny>=n) continue;
            if (grass[nx][ny] == 0 ){
                grass[nx][ny] = 2;
                board[nx][ny] = board[x][y] +1;
                if (board[nx][ny] > res){
                    res = board[nx][ny];
                }
                Q.push({nx,ny});
            }

        }
    }
    return res;
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
    cout << bfs(n);
}