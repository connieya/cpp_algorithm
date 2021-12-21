#include "stdio.h"

int n, m;
int arr[8];
bool visited[9];

void dfs(int l, int start) {
    if (l == m) {
        for (int i = 0; i < m; ++i) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = start; i <= n; ++i) {
            arr[l] = i;
            dfs(l + 1,i);
        }
    }


int main(void) {
    scanf("%d %d", &n, &m);
    dfs(0,1);
}