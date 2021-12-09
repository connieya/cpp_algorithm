#include "stdio.h"
#include "iostream"
#define N 100001

int main(void) {
    int arr[N] = {0};
    int n, k, tmp, j, cnt = 0;
    scanf("%d", &n);
    scanf("%d", &k);
    for (int i=2; i<=n; i++){
        if(arr[i]){
            continue;
        }
        for (int j=i; j<=n; j+=i){
            arr[j] = std::max(arr[j],i);
        }
    }
    for (int i = 1; i <= n; ++i) {
       if(arr[i]<=k){
           cnt++;
       }
    }
    printf("%d", cnt);
}