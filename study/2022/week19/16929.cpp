#include "bits/stdc++.h"

using namespace std;

int n,m;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
char board[51][51];
bool checked[51][51];


bool dfs(int x, int y ,int pre_x,int pre_y, char color){
    if(checked[x][y]) return true;
    checked[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int nx = x +dx[i];
        int ny = y +dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(nx == pre_x && ny == pre_y) continue;
        if(board[nx][ny] == color && dfs(nx,ny ,x ,y ,color)) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(!checked[i][j] && dfs(i,j,-1,-1,board[i][j] )) {
                cout << "Yes";
                exit(0);
            }
        }
    }
    cout << "No";
}