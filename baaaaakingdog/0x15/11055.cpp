#include <algorithm>
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
        dp[i] = arr[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]){
                dp[i] = max(dp[i],arr[i]+dp[j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans , dp[i]);
    }
    printf("%d",ans);

}