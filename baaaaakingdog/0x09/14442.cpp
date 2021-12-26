#include "stdio.h"
#include "queue"
#include "tuple"

using namespace std;

typedef pair<int, int> Pos;
struct state {
    Pos p;
    int cnt;
    bool overCrushWall;
};

char map[1000][1000];
int dist[1000][1000][2]; // dist[][][0] : 벽 을 k번 미만 부숨 , dist[][][1] : 벽 k번 부숨
int n, m;


int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    int k;
    scanf("%d %d %d", &n, &m, &k);
    queue<state> Q;
    for (int i = 0; i < n; ++i) {
        scanf("%s", map[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            dist[i][j][0] = -1;
            dist[i][j][1] = -1;
        }
    }
    dist[0][0][0] = 1;
    dist[0][0][1] = 1;
    Q.push(state{{0, 0}, 0, false});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int curX = cur.p.first;
        int curY = cur.p.second;
        int cnt = cur.cnt;
        bool isOverCrushWall = cur.overCrushWall;
        if (curX == n - 1 && curY == m - 1) {
            printf("%d", dist[curX][curY][isOverCrushWall]);
            return 0;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || cnt > k) continue;
            if (map[nx][ny] == '0' && cnt < k && dist[nx][ny][isOverCrushWall] == -1) {
                dist[nx][ny][isOverCrushWall] = dist[curX][curY][isOverCrushWall] + 1;
                Q.push(state{{nx, ny}, cnt, isOverCrushWall});
            } else if (map[nx][ny] == '0' && cnt == k && dist[nx][ny][isOverCrushWall] == -1) {
                dist[nx][ny][true] = dist[curX][curY][isOverCrushWall] + 1;
                Q.push(state{{nx, ny}, cnt, isOverCrushWall});
            } else if (map[nx][ny] == '1' && cnt < k && dist[nx][ny][isOverCrushWall] == -1) {
                dist[nx][ny][isOverCrushWall] = dist[curX][curY][isOverCrushWall] + 1;
                Q.push(state{{nx, ny}, cnt + 1, isOverCrushWall});
            } else if (map[nx][ny] == '1' && cnt == k && dist[nx][ny][isOverCrushWall] == -1) {
                dist[nx][ny][true] = dist[curX][curY][isOverCrushWall] + 1;
                Q.push(state{{nx, ny}, cnt + 1, isOverCrushWall});
            }
        }
    }
    printf("%d", -1);
}