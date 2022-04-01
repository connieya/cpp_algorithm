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
    if (sum > ans) {
        ans = sum;
    }
    if (n==x) return;
    for (int i = n; i < x; ++i) {
        for (int j = m; j < y; ++j) {
            for (int k = 0; k < 4; ++k) {
                int nx = boomerang[k].first + i;
                int ny = boomerang[k].second + j;
                if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
                if (!visited[i][j] && !visited[nx][j] && !visited[i][ny]) {
                    visited[i][j] = visited[nx][j] = visited[i][ny] = true;
                    dfs(i, j + 1, sum + (arr[i][j] * 2) + arr[nx][j] + arr[i][ny]);
                    visited[i][j] = visited[nx][j] = visited[i][ny] = false;
                }
            }
        }
    }
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
    dfs(0, 0, 0);
    cout << ans;
}