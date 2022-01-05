#include "stdio.h"

int arr[500][500];
int dp[500][500];
int a, b;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int dfs(int x, int y, int prev) {
    if (x == a - 1 && y == b - 1) {
        return 1;
    }
    if (dp[x][y] == -1) {
        dp[x][y] = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx < 0 || nx >= a || ny < 0 || ny >= b) continue;
            int next = arr[nx][ny];
            if (prev > next) {
                dp[x][y] += dfs(nx, ny, arr[nx][ny]);
            }
        }
    }
    return dp[x][y];


}

int main(void) {
    scanf("%d %d", &a, &b);
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            scanf("%d", &arr[i][j]);
            dp[i][j] = -1;
        }
    }
    printf("%d", dfs(0, 0, arr[0][0]));
}