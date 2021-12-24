#include "stdio.h"

int n , m , ans;
int arr[10];

void dfs(int L ,int sum) {
    if (L == n) {
        if (sum == m){
            ans++;
        }
        return;
    }
    dfs(L+1, sum+arr[L]);
    dfs(L+1, sum-arr[L]);
    dfs(L+1, sum);
}

int main(void)
{
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    dfs(0,0);
    printf("%d",ans);
}