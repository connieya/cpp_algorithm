#include "bits/stdc++.h"

using namespace std;

int n, m;
int board[301][301];
int visited[301][301];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int x ,int y){
    visited[x][y] = true;
    queue<pair<int,int>> q;
    q.push({x,y});
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(visited[nx][ny]) continue;
            if(board[nx][ny] > 0){
                visited[nx][ny] = true;
                q.push({nx,ny});
            }else {
                board[x][y] -= 1;
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
    int ans = 0;
    while (1) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] > 0 && !visited[i][j]) {
                    cnt++;
                    bfs(i,j);
                }
            }
        }
        if(cnt == 0) {
            cout << 0;
            exit(0);
        }
        if (cnt > 1) break;
        ans++;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                visited[i][j] = false;
            }
        }
    }
    cout << ans;
}