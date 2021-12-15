#include "stdio.h"

int land[701][701], dy[701][701];

int main(void) {
    int n, m, n2, m2 , max = -1;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &land[i][j]);
            dy[i][j] = dy[i - 1][j] + dy[i][j - 1] - dy[i - 1][j - 1] + land[i][j];
        }
    }
    scanf("%d %d", &n2, &m2);
    for (int i = n2; i <= n; ++i) {
        for (int j = m2; j <= m; ++j) {
            int tmp = dy[i][j] - dy[i-n2][j] - dy[i][j-m2] + dy[i-n2][j-m2];
            if(tmp > max) {
                max =tmp;
            }
        }
    }
    printf("%d",max);

}