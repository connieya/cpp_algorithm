#include "stdio.h"
#include "queue"
#include "tuple"

using namespace std;
queue<tuple<int, int, int>> Q;

int M, N, H;
int box[100][100][100];

int dx[] = {-1, 0, 1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int main(void) {
    int MX = 1;
    bool flag = false;
    scanf("%d %d %d", &M, &N, &H);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                scanf("%d", &box[j][k][i]);
                if (box[j][k][i] == 1) {
                    Q.push({j, k, i});
                }
            }
        }
    }
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int curX, curY, curZ;
        tie(curX, curY, curZ) = cur;
        for (int i = 0; i < 6; i++) {
            int nx = dx[i] + curX;
            int ny = dy[i] + curY;
            int nz = dz[i] + curZ;
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && nz >= 0 && nz < H && box[nx][ny][nz] == 0) {
                box[nx][ny][nz] = box[curX][curY][curZ] + 1;
                Q.push({nx,ny,nz});
            }
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                if (box[j][k][i] == 0) {
                    printf("-1");
                    return 0;
                }
                MX = max(MX, box[j][k][i]);
            }

        }
    }
    printf("%d", MX - 1);

}