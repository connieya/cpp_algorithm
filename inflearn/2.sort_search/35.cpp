#include "stdio.h"
#include "vector"

int main(void) {
    int n;
    scanf("%d", &n);
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1-i; j++){
            if(arr[j]>0 && arr[j+1]<0){
                int tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    for (int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
}