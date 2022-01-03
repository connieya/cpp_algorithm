#include "stdio.h"
#include "algorithm"

using namespace std;

int main(void) {
    int n, total, mid, result;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &total);
    sort(arr, arr + n);
    int lt = arr[0];
    int rt = arr[n - 1];
    while (lt <= rt) {
        mid = (lt + rt) / 2;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += min(mid, arr[i]);
        }
        if (sum <= total) {
            result = mid;
            lt = mid + 1;
        } else {
            rt = mid - 1;
        }
    }
    printf("%d", result);
}