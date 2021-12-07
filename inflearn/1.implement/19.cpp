#include "stdio.h"

int main(void) {
    int n = 0;
    scanf("%d", &n);
    int arr[100] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    int count = 0;
    int max = arr[n-1];
    for (int i=n-2; i>=0; i--){
        if(arr[i] > max){
            max = arr[i];
            count++;
        }
    }
    printf("%d",count);
}