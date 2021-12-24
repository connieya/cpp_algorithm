#include "stdio.h"

int arr[21][21];
bool visited[21];
int n , cnt;

void dfs(int L) {
    if (L == n) {
        cnt++;
    }
    for (int i = 1; i <=n ; ++i) {
        if (arr[L][i] == 1 && !visited[L]){
            visited[L] = true;
            dfs(i);
            visited[L] = false;
        }
    }
}


int main(void)
{
    int m,a,b;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d",&a,&b);
        arr[a][b] = 1;
    }
    dfs(1);
    printf("%d",cnt);
}