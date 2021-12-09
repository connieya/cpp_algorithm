#include "stdio.h"

int main() {
    int arr[100], n, idx, i, j, tmp;
    scanf("%d",&n);
    for (i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    for (i=0; i<n-1; i++){
        idx = i;
        for (j=i+1; j<n; j++){
            if(arr[idx] > arr[j]){
                idx = j;
            }
        }
        tmp = arr[idx];
        arr[idx] = arr[i];
        arr[i] = tmp;
    }
    for (i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
}