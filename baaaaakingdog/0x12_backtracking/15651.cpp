#include "stdio.h"

int n, m;
int arr[8];

void dfs(int l) {
    if (l == m) {
        for (int i = 0; i < m; ++i) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; ++i) {
            arr[l] = i;
            dfs(l + 1);
        }
    }

int main(void) {
    scanf("%d %d", &n, &m);
    dfs(0);
}