#include "bits/stdc++.h"

using namespace std;

int r,c,k ,ans = 0;
char mp[6][6];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void dfs(int x , int y , int dis) {
    if (x== 0 && y == c-1) {
        if (dis == k) ans++;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = dx[i]+x;
        int ny = dy[i]+y;
        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if (mp[nx][ny] == '.'){
            mp[nx][ny] = 'w';
            dfs(nx,ny,dis+1);
            mp[nx][ny] = '.';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c >> k;
    for (int i = 0; i < r; ++i) {
        cin >> mp[i];
    }
    mp[r-1][0] = 'w';
    dfs(r-1,0,1);
    cout << ans;
}