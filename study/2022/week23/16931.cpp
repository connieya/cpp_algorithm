#include "bits/stdc++.h"

using namespace std;

int n,m;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int board[105][105];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> board[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 0; k < 4; ++k) {
                int nx = dx[k]+i;
                int ny = dy[k]+j;
                if(board[i][j] > board[nx][ny]){
                    ans += board[i][j] - board[nx][ny];
                }
            }
        }
    }
    ans += n*m*2;
    cout << ans;

}