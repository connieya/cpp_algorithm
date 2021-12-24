#include "stdio.h"

int n;
bool visited[11];
void dfs(int L) {
    if (L==n+1){
        for (int i = 1; i <= n; ++i) {
            if (visited[i]){
                printf("%d ",i);
            }
        }
        printf("\n");
        return;
    }
    visited[L] = true;
    dfs(L+1);
    visited[L] = false;
    dfs(L+1);
}

int main(void)
{
    n;
    scanf("%d",&n);
    dfs(1);
}