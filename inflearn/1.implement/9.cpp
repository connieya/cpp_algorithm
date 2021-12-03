#include "stdio.h"

int main() {
    int n, i, j;
    scanf("%d", &n);
    int arr[50001] = {0};
    for (i = 1; i <= n; ++i) {
        for (j = i; j <= n; j += i) {
            arr[j] = arr[j] + 1;
        }
    }
    for (i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
}