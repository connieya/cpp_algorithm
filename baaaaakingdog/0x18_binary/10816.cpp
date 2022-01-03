#include "stdio.h"
#include "algorithm"

using namespace std;


int main(void) {
    int n, m, target;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &target);
        printf("%d ", upper_bound(arr, arr + n, target) - lower_bound(arr, arr + n, target));
    }
}