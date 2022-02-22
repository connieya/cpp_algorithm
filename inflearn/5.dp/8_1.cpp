#include "bits/stdc++.h"

using namespace std;

int n;
int arr[21][21];
int dp[21][21];

int dfs(int x, int y) {
    if (dp[x][y] > 0) return dp[x][y];
    if (x == 0 && y == 0) {
        return arr[0][0];
    }
    if (y==0) return dfs(x-1,y)+arr[x][y];
    if (x==0) return dfs(x,y-1)+arr[x][y];
    return min(dfs(x-1,y), dfs(x,y-1))+arr[x][y];

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    cout << dfs(n-1,n-1);
}