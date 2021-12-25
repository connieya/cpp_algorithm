#include "stdio.h"

int dy[21][21];

int dfs(int n, int r){
    if (n==r || r == 0){
        return 1;
    }
    if (dy[n][r] > 0) {
        return dy[n][r];
    }
    return dy[n][r] =dfs(n-1,r-1)+ dfs(n-1,r);
}

int main(void)
{
    int n ,r;
    scanf("%d %d",&n,&r);
    printf("%d", dfs(n ,r));
}