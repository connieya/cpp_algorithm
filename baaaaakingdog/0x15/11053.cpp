#include "stdio.h"

int main(void)
{
    int n;
    scanf("%d",&n);
    int arr[n+1] , dp[n+1];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        dp[i] = 1;
        int max = 0;
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && dp[j] > max){
                max = dp[j];
            }
        }
        dp[i] = max +1;
    }
    int ans  = -1;
    for (int i = 0; i < n; ++i) {
        if (dp[i] > ans){
            ans = dp[i];
        }
    }
    printf("%d",ans);
}