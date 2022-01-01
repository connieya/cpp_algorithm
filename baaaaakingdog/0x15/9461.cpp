#include "stdio.h"

int main(void) {
    int t, temp;
    scanf("%d", &t);
    int arr[101];
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 2;
    arr[5] = 2;
    for (int i = 6; i <= 100; ++i) {
        arr[i] = arr[i - 1] + arr[i - 5];
    }
    while (t--) {
        scanf("%d", &temp);
        printf("%d\n", arr[temp]);
    }
}