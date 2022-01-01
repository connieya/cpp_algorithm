#include "stdio.h"

int main(void)
{
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[11];
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&arr[i]);
    }
    int ans = 0;
    while (k > 0){
        if (k / arr[n]){
            ans += k / arr[n];
            k %= arr[n];
        }
        n--;
    }
    printf("%d",ans);
}