#include "stdio.h"

int map[8][8];
bool visited[8][8];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int cnt;

void dfs(int x, int y) {
    if (x == 7 && y == 7) {
        cnt++;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx>=1 && nx <=7 && ny>=1 && ny <=7 && !visited[nx][ny] && map[nx][ny] == 0){
            visited[nx][ny] = true;
            dfs(nx,ny);
            visited[nx][ny] = false;
        }
    }
}

int main(void) {
    for (int i = 1; i <= 7; ++i) {
        for (int j = 1; j <= 7; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    visited[1][1] = true;
    dfs(1,1);
    printf("%d",cnt);
}