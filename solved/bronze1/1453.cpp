#include "stdio.h"

int main()
{
    int arr[101] = {0} ,n , idx , cnt = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&idx);
        if(arr[idx] == 0){
            arr[idx]++;
        }else{
            cnt++;
        }
    }
    printf("%d",cnt);
}