#include "stdio.h"

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(void) {
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    int arr[300][300] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int group = n > m ? m / 2 : n / 2;
    while (r--) {
        for (int i = 0; i < group; ++i) {
            int x = i;
            int y = i;
            int value = arr[x][y];
            int dir = 0;
            while (dir < 4){
                int nx = x +dx[dir];
                int ny = y + dy[dir];
                if(nx>=i && nx < n-i && ny >= i && ny<m-i){
                    arr[x][y] = arr[nx][ny];
                    x = nx;
                    y= ny;
                }else {
                    dir++;
                }
            }
            arr[x+1][y] = value;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

}