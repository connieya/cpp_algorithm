#include "stdio.h"

int map[20][20];
int dice[4][3];
int n, m, x1, y1, k;

void play(int x, int y, int dir);

void move_dice(int dir);

int dx[] = {0, 0, 0, -1, 1}; // 1: 동쪽 , 2: 서쪽
int dy[] = {0, 1, -1, 0, 0}; // 3: 북쪽 , 4 : 남쪽
int main(void) {
    int dir;
    scanf("%d %d %d %d %d", &n, &m, &x1, &y1, &k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i < k; ++i) {
        scanf("%d", &dir);
        play(x1, y1, dir);
    }
}

void move_dice(int dir) {
    if (dir == 1) {
        int tmp = dice[1][2];
        dice[1][2] = dice[1][1];
        dice[1][1] = dice[1][0];
        dice[1][0] = dice[3][1];
        dice[3][1] = tmp;
        return;
    }
    if (dir == 2) {
        int tmp = dice[1][0];
        dice[1][0] = dice[1][1];
        dice[1][1] = dice[1][2];
        dice[1][2] = dice[3][1];
        dice[3][1] = tmp;
        return;
    }
    if (dir == 3) {
        int tmp = dice[0][1];
        dice[0][1] = dice[1][1];
        dice[1][1] = dice[2][1];
        dice[2][1] = dice[3][1];
        dice[3][1] = tmp;
        return;
    }
    if (dir == 4) {
        int tmp = dice[3][1];
        dice[3][1] = dice[2][1];
        dice[2][1] = dice[1][1];
        dice[1][1] = dice[0][1];
        dice[0][1] = tmp;
        return;
    }
}


void play(int x, int y, int dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        move_dice(dir);
        if (map[nx][ny] == 0) {
            map[nx][ny] = dice[3][1];
        } else {
            dice[3][1] = map[nx][ny];
            map[nx][ny] = 0;
        }
        printf("%d\n", dice[1][1]);
        x1 = nx;
        y1 = ny;
    }
}