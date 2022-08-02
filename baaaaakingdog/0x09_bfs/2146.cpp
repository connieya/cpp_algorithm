#include "bits/stdc++.h"

using namespace std;

int n , ans = INT_MAX;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int mp[101][101];
int dist[101][101];
int g[101][101];

void bfs(int x, int y, int idx) {
    g[x][y] = idx;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || !mp[nx][ny]) continue;
            if (g[nx][ny] == 0) {
                q.push({nx, ny});
                g[nx][ny] = idx;
            }
        }
    }
}





int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mp[i][j];
            dist[i][j] = -1;
        }
    }

    int idx = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mp[i][j] && g[i][j] == 0) {
                bfs(i, j, idx);
                idx++;
            }
        }
    }

    queue<pair<int,int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(mp[i][j]){
                dist[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    while (!q.empty()){
        int x= q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x +dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >=n) continue;
            if(g[nx][ny] && g[nx][ny] != g[x][y]){
                if(ans > dist[nx][ny]+dist[x][y]){
                    ans = dist[nx][ny]+dist[x][y];
                }
            }
            if(dist[nx][ny] == -1){
                dist[nx][ny] = dist[x][y]+1;
                g[nx][ny]= g[x][y];
                q.push({nx,ny});
            }

        }
    }
    cout << ans;

}