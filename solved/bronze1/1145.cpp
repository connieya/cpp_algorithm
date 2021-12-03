#include "stdio.h"

int main() {
    int arr[5];
    int n = 5;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int num = 4;
    while (true){
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if(num % arr[i] == 0){
                count++;
            }
        }
        if(count >= 3){
            break;
        }
        num++;
    }
    printf("%d",num);
}