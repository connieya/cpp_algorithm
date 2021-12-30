#include "stdio.h"

int main(void)
{
    int n,m,tmp;
    int x ,y;
    scanf("%d %d",&n,&m);
    int arr[n+1];
    arr[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&tmp);
        arr[i] = arr[i-1] + tmp;
    }
    while (m--) {
        scanf("%d %d",&x,&y);
        printf("%d\n",arr[y]-arr[x-1]);
    }
}