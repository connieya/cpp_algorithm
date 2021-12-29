#include "stdio.h"
#include "queue"
#include "tuple"

using namespace std;

int w, h, k;
int board[200][200];
int ans[32][200][200];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dxt[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dyt[] = { 1, -1, 2, -2, 2, -2, 1, -1 };

bool isOutOfBounds(int nx, int ny) {
    if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
        return true;
    }
    return false;
}

int main(void) {
    scanf("%d", &k); // 횟수
    scanf("%d %d", &w, &h); // w 열 , h 행
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf("%d", &board[i][j]);
        }
    }
    queue<tuple<int, int, int>> Q; // 행 , 열 , 횟수
    Q.push({0, 0, 0});
    ans[0][0][0] = 1;
    while (!Q.empty()) {
        int x, y, z, nx, ny;
        tie(z, x, y) = Q.front();
        Q.pop();
        if (z < k) {
            for (int i = 0; i < 8; ++i) {
                nx = dxt[i] + x;
                ny = dyt[i] + y;
                if (isOutOfBounds(nx, ny)) continue;
                if (board[nx][ny]) continue;
                if (ans[z + 1][nx][ny]) continue;
                ans[z + 1][nx][ny] = ans[z][x][y] + 1;
                Q.push({z + 1, nx, ny});

            }
        }
        for (int i = 0; i < 4; ++i) {
            nx = dx[i] + x;
            ny = dy[i] + y;
            if (isOutOfBounds(nx, ny)) continue;
            if (board[nx][ny]) continue;
            if (ans[z][nx][ny]) continue;
            ans[z][nx][ny] = ans[z][x][y] + 1;
            Q.push({z, nx, ny});
        }
    }
    int tt = 0x7f7f7f7f;
    for (int i = 0; i<= k; ++i) {
        if (ans[i][h - 1][w - 1]) {
            tt = min(tt, ans[i][h - 1][w - 1]);
        }
    }
    if (tt != 0x7f7f7f7f) {
        printf("%d", tt - 1);
    } else {
        printf("-1");
    }

}