#include "bits/stdc++.h"

using namespace std;

int MAP[51][51];
bool visited[51][51];
int x,y,dir ,ans =1;

void rotate() {
    dir--;
    if (dir < 0) {
        dir =3;
    }
}
int dx[] = {-1,0,1,0}; // 북 동 남 서
int dy[] = {0,1,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    cin >> x >> y >> dir;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> MAP[i][j];
        }
    }
    queue<pair<int ,int>> Q;
    Q.push({x,y});
    visited[x][y] = true;
    while (!Q.empty()){
        auto now = Q.front();
        int x = now.first;
        int y = now.second;
        Q.pop();
        int cnt = 0;
        for (int i = 0; i < 4; ++i) {
            rotate();
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >=n || ny < 0 || ny >= m) {
                continue;
            }
            if (MAP[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                ans++;
                Q.push({nx,ny});
                cnt = 0;
                break;
            }
            cnt++;
        }
        if (cnt == 4) {
            int nx = x -dx[dir];
            int ny = y-dy[dir];
            if (nx >=0 && nx <n && ny >=0 && ny < m && MAP[nx][ny] == 0 && !visited[nx][ny]){
                visited[nx][ny] = true;
                Q.push({nx,ny});
                ans++;
            }
        }
    }
    cout << ans;

}