#include "bits/stdc++.h"

using namespace std;

char ch[101][101];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void bfs(int x, int y, int r , int c) {
    ch[x][y] = '.';
    queue<pair<int,int>> Q;
    Q.push({x,y});
    while (!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;
            if (nx < 0 || nx >=r || ny < 0 || ny>=c) {
                continue;
            }
            if (ch[nx][ny] == '#'){
                ch[nx][ny] = '.';
                Q.push({nx,ny});
            }
        }
    }
}

int solve(int r ,int c) {
    int cnt = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (ch[i][j] == '#'){
                cnt++;
                bfs(i,j,r,c);
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
    int t;
    cin >> t;
    while (t--) {
        int r,c;
        cin >> r >> c;
        for (int i = 0; i < r; ++i) {
            cin >> ch[i];
        }
        cout << solve(r,c) << '\n';
    }
}