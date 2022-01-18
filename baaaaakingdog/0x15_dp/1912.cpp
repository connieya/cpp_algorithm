#include "stdio.h"

using namespace std;
int main(void)
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int dp[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    dp[0] = arr[0];
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i+1] > arr[i]+arr[i+1]){
                dp[i+1] = arr[i+1];
        }else {
            dp[i+1] = arr[i]+arr[i+1];
            arr[i+1] = dp[i+1];
        }
    }
    int MAX = -214700000;
    for (int i = 0; i < n; ++i) {
        if(dp[i] > MAX) {
            MAX = dp[i];
        }
    }
    printf("%d",MAX);
}
