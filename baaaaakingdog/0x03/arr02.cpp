#include "stdio.h"

int func2(int arr[] , int n){
    int num[101] = {0};
    for (int i = 0; i < n; ++i) {
        if(num[100-arr[i]]){
            return 1;
        }
        num[arr[i]] = 1;
    }
    return 0;
}

int main()
{
    int arr[5] = {1,23,53,77,60};
    printf("%d \n", func2(arr,5));
}