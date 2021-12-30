#include "stdio.h"
#include "algorithm"

using namespace std;
int main(void) {
    int n;
    scanf("%d", &n);
    int arr[n][3];
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }
    for (int i = 1; i < n; ++i) {
        arr[i][0] = arr[i][0] + min(arr[i-1][1],arr[i-1][2]);
        arr[i][1] = arr[i][1] + min(arr[i-1][0],arr[i-1][2]);
        arr[i][2] = arr[i][2] + min(arr[i-1][0],arr[i-1][1]);
    }
    printf("%d", min(arr[n-1][0], min(arr[n-1][1],arr[n-1][2])));
}