#include "stdio.h"
#include "queue"
#include "tuple"

using namespace std;
char map[1000][1000];
int dist[1000][1000][2]; // dist[][][0] : 벽 한번도 안부숨 , dist[][][1] : 벽 한번이라도 부순
int n, m;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    scanf("%d %d", &n, &m);
    queue<tuple<int, int, bool> > Q;
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
    Q.push({0, 0, false});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int curX, curY;
        bool crushWall;
        tie(curX, curY, crushWall) = cur;
        if (curX == n-1 && curY == m-1){
            printf("%d",dist[curX][curY][crushWall]);
            return 0;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (map[nx][ny] == '0' && dist[nx][ny][crushWall] == -1) {
                dist[nx][ny][crushWall] = dist[curX][curY][crushWall] + 1;
                Q.push({nx, ny, crushWall});
            } else if (map[nx][ny] == '1' && !crushWall && dist[nx][ny][crushWall] == -1) {
                dist[nx][ny][true] = dist[curX][curY][crushWall] + 1;
                Q.push({nx, ny, true});
            }
        }
    }
    printf("%d", -1);
}