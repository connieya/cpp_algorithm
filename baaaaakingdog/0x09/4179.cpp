#include "stdio.h"
#include "queue"

char miro[1000][1000];
int fire[1000][1000];
int jihoon[1000][1000];
bool visited[1000][1000];
bool visited2[1000][1000];
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

queue<pair<int, int>> f;
queue<pair<int, int>> jh;

int main(void) {
    int R, C , ans = 0;
    bool isEscaped = false;
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; ++i) {
        scanf("%s", miro[i]);
        for (int j = 0; j < C; ++j) {
            if (miro[i][j] == '#') {
                fire[i][j] = -1;
                jihoon[i][j] = -1;
                continue;
            }
            if (miro[i][j] == 'J') {
                jh.push({i, j});
                visited2[i][j] = true;
                continue;
            }
            if (miro[i][j] == 'F') {
                visited[i][j] = true;
                f.push({i, j});
                continue;
            }
        }
    }
    while (!f.empty()) {
        auto cur = f.front(); f.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] +cur.second;
            if (nx >=0 && nx <R && ny >=0 && ny < C  && fire[nx][ny] != -1 && !visited[nx][ny] ){
                visited[nx][ny] = true;
                fire[nx][ny] = fire[cur.first][cur.second] +1;
                f.push({nx,ny});
            }
        }
    }

    while (!jh.empty()) {
        auto cur = jh.front(); jh.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;
            if (nx < 0 || nx >=R || ny < 0 || ny >=C){
                isEscaped = true;
                ans = jihoon[cur.first][cur.second] +1;
                break;
            }
            if (isEscaped){
                break;
            }
            if (jihoon[nx][ny] == -1 || visited2[nx][ny]) continue;

            if (jihoon[cur.first][cur.second] +1 < fire[nx][ny] || fire[nx][ny] == 0){
                visited2[nx][ny] = true;
                jihoon[nx][ny] = jihoon[cur.first][cur.second]+1;
                jh.push({nx,ny});
            }
        }
    }
    if (isEscaped){
        printf("%d",ans);
    }else{
        printf("IMPOSSIBLE");
    }
}