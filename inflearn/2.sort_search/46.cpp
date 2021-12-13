#include "stdio.h"

int arr[2001];
int main(void)
{
    int n ,k, total = 0 , pos = 0 , time =0;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&arr[i]);
        total += arr[i];
    }
    scanf("%d",&k);
    if(k>=total){
        printf("-1\n");
        return 0;
    }
    while (time < k) {
        pos++;
        if(pos > n){
            pos =1;
        }
        if(arr[pos] == 0){
            continue;
        }
        arr[pos]--;
        time++;
    }
    while (1){
        pos++;
        if(pos>n){
            pos=1;
        }
        if(arr[pos] ==0){
            continue;
        }
        if(arr[pos]>0){
            break;
        }
    }
    printf("%d\n",pos);
}