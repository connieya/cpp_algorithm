#include "stdio.h"
#define max(a, b) a>b?a:b
int land[50][50];

int main(void) {
    int n, m, n1, m1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &land[i][j]);
        }
    }
    int max = -1;
    scanf("%d %d", &n1, &m1);
    for (int i = 0; i <= n - n1; ++i) {
        for (int j = 0; j <= m - m1; ++j) {
            int sum = 0;
            for (int k = i; k < i + n1; ++k) {
                for (int l = j; l < j + m1; ++l) {
                    sum += land[k][l];
                }
            }
            max = max(max,sum);
        }
    }
    printf("%d",max);
}