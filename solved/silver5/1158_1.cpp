#include "stdio.h"
#include "vector"

int main()
{
    int n,k, cnt =0 , bp = 0 , idx =0;
    scanf("%d %d",&n,&k);
    std::vector<int> arr(n+1);
    printf("<");
    while (bp < n-1) {
        idx++;
        if(idx > n){
            idx =1;
        }
        if(arr[idx] == 0){
            cnt++;
            if(cnt == k){
                cnt = 0;
                arr[idx] = 1;
                printf("%d, ",idx);
                bp++;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if(!arr[i]){
            printf("%d>",i);
            break;
        }
    }
}