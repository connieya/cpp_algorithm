#include "stdio.h"
#include "queue"

char miro[1000][1000];
int fire[1000][1000];
int jihoon[1000][1000];

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    int R, C;
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; ++i) {
        scanf("%s", miro[i]);
        fill(jihoon[i], jihoon[i] + C, -1);
        fill(fire[i], fire[i] + C, -1);
    }
    queue<pair<int, int>> f;
    queue<pair<int, int >> jh;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (miro[i][j] == 'J') {
                jh.push({i, j});
                jihoon[i][j] = 0;

            }
            if (miro[i][j] == 'F') {
                f.push({i, j});
                fire[i][j] = 0;
            }
        }
    }
    while (!f.empty()) {
        auto cur = f.front();
        f.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                continue;
            }
            if (miro[nx][ny] != '#' && fire[nx][ny] == -1) {
                fire[nx][ny] = fire[cur.first][cur.second] + 1;
                f.push({nx, ny});
            }
        }
    }
    while (!jh.empty()) {
        auto cur = jh.front();
        jh.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                printf("%d", jihoon[cur.first][cur.second] + 1);
                return 0;
            }

            if (miro[nx][ny] == '.' && jihoon[nx][ny] == -1 && jihoon[cur.first][cur.second] + 1 < fire[nx][ny]) {
                jihoon[nx][ny] = jihoon[cur.first][cur.second] + 1;
                jh.push({nx, ny});
            }
        }
    }
    printf("IMPOSSIBLE ");
}