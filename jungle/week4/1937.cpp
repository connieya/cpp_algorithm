#include "bits/stdc++.h"

using namespace std;

int arr[501][501];
int visited[501][501];
int n;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int ans;

void dfs(int x , int y) {
    for (int i = 0; i < 4; ++i) {
        int nx = x +dx[i];
        int ny = y +dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (arr[x][y] < arr[nx][ny]){
            if (visited[nx][ny] == 0) dfs(nx,ny);
            visited[x][y] = max(visited[x][y] , visited[nx][ny]+1);
        }
    }
    ans = max(ans,visited[x][y]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j] == 0){
                dfs(i,j);
            }
        }
    }
    cout << ans+1;
}