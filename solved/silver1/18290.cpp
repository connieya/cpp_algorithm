#include "bits/stdc++.h"

using namespace std;

int arr[11][11];
bool visited[11][11];
int n,m,k ,ans = -INT_MIN;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

bool isNotClose(int x ,int y){
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (visited[nx][ny]) return false;
    }
    return true;
}

void dfs(int L , int sum) {
    if (L == k) {
        if (sum > ans){
            ans = sum;
        }
        return;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && isNotClose(i,j)){
                visited[i][j] = true;
                dfs(L+1, sum+arr[i][j]);
                visited[i][j] = false;
            }
        }

    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    dfs(0,0);
    cout << ans;

}