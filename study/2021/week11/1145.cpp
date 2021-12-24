#include "stdio.h"

int main() {
    int arr[5] = {0};
    scanf("%d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
    int result = 4;
    while (true) {
        int count = 0;
        for (int i = 0; i < 5; i++) {
            if (result % arr[i] == 0) {
                count++;
            }
        }
        if (count >= 3) {
            break;
        }
        result++;
    }
    printf("%d", result);
}