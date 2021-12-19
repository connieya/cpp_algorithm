#include "stdio.h"
#include "queue"

using namespace std;
char grid[100][100];
char tmp[100][100];
queue<pair<int, int>> Q;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int x, int y, char ch);

int n;
bool isColorWeakness = false;

int main(void) {
    int a = 0, b = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (tmp[i][j] != 'c') {
                tmp[i][j] = 'c';
                a++;
                bfs(i, j, grid[i][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tmp[i][j] = 'e';
        }
    }
    isColorWeakness = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (tmp[i][j] != 'c') {
                tmp[i][j] = 'c';
                b++;
                bfs(i, j, grid[i][j]);
            }
        }
    }
    printf("%d %d", a, b);

}

void bfs(int i, int j, char standard) {
    Q.push({i, j});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = dx[k] + cur.first;
            int ny = dy[k] + cur.second;
            if (!isColorWeakness) {
                if (nx >= 0 && ny < n && ny >= 0 && ny < n && tmp[nx][ny] != 'c' && grid[nx][ny] == standard) {
                    tmp[nx][ny] = 'c';
                    Q.push({nx, ny});
                }
            } else {
                if (nx < 0 || nx >=n || ny < 0 || ny >=n) continue;
                if (tmp[nx][ny] == 'c') continue;
                if (grid[nx][ny]== standard){
                    tmp[nx][ny] = 'c';
                    Q.push({nx,ny});
                }
                if ((standard == 'R' && grid[nx][ny] == 'G') || (standard =='G' && grid[nx][ny]== 'R')){
                    tmp[nx][ny] ='c';
                    Q.push({nx,ny});
                }
            }
        }
    }
}