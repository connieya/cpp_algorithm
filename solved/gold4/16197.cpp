#include "bits/stdc++.h"

using namespace std;

int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char board[21][21];
bool visited[21][21];
int checked[21][21];

void init(){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visited[i][j] = false;
        }
    }
}

int dfs(int x, int y, int cnt) {
    if (x < 0 || x > n || y < 0 || y > m) {
        return cnt;
    }
    cout << x << ' ' << y <<  ' ' << cnt <<'\n';
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!visited[nx][ny] && board[nx][ny] != '#') {
            visited[nx][ny] = true;
            checked[nx][ny]++;
            dfs(nx, ny, cnt + 1);
        }

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(board[i][j] == 'o'){
                checked[i][j]++;
                visited[i][j] = true;
                ans = min(ans ,dfs(i,j,0));
                cout << '\n';
                init();
            }
        }
    }
    cout << ans;


}