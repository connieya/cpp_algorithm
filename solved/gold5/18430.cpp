#include "bits/stdc++.h"

using namespace std;

int arr[5][5];
bool visited[5][5];
int ans = 0;
int x, y;
pair<int, int> boomerang[4] = {{1,  1},
                               {1,  -1},
                               {-1, 1},
                               {-1, -1}};

void dfs(int n, int m, int sum) {
    if (m == y) {
        m = 0;
        n++;
    }
    if (n == x) {
        ans = max(ans,sum);
        return;
    }

    for (int k = 0; k < 4; ++k) {
        int nx = boomerang[k].first + n;
        int ny = boomerang[k].second + m;
        if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
        if (!visited[n][m] && !visited[nx][m] && !visited[n][ny]) {
            visited[n][m] = visited[nx][m] = visited[n][ny] = true;
            dfs(n, m + 1, sum + (arr[n][m] * 2) + arr[nx][m] + arr[n][ny]);
            visited[n][m] = visited[nx][m] = visited[n][ny] = false;
        }
    }
    dfs(n, m+1, sum);
}


int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> y;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            dfs(i, j, 0);
        }
    }

    cout << ans;
}