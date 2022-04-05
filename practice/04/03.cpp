#include "bits/stdc++.h"

using namespace std;

int arr[101][101];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int n,m,k;

int bfs(int x ,int y) {
    int cnt = 1;
    arr[x][y] = 0;
    queue<pair<int,int>> Q;
    Q.push({x,y});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int a = cur.first;
        int b = cur.second;
        for (int i = 0; i < 4; ++i) {
            int nx = dx[i] + a;
            int ny = dy[i] + b;
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (arr[nx][ny] == 1){
                cnt++;
                arr[nx][ny] = 0;
                Q.push({nx,ny});
            }
        }
    }
    return cnt;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }
    int answer = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (arr[i][j] == 1) {
                int cnt = bfs(i,j);
                if (cnt > answer){
                    answer = cnt;
                }
            }
        }
    }
    cout << answer;
}