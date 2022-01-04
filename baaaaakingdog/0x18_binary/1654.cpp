#include "stdio.h"
#include "algorithm"

using namespace std;

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    long long ans = 0;
    long long lt = 0;
    long long rt = arr[n - 1];
    while (lt < rt) {
        long long mid = (lt + rt+1) / 2;
        long long cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] >= mid) {
                cnt += arr[i] / mid;
            }
        }
        if (cnt >= k) {
            ans = mid;
            lt = mid ;
        } else {
            rt = mid - 1;
        }
    }
    printf("%lld",ans);
}