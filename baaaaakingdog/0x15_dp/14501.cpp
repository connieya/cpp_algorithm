#include "stdio.h"
#include "algorithm"

using namespace std;
int main(void)
{
    int arr[16][2];
    int n , time , pay ,j;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d",&time,&pay);
        arr[i][0] = time+i;
        arr[i][1] = pay;
        if (time + i > n+1){
            arr[i][1] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int max = 0;
        for (j = 0; j < i; ++j) {
            if (i >= arr[j][0] && arr[j][1] > max) {
                    max = arr[j][1];
            }
        }
        arr[i][1] += max;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (arr[i][1] > ans){
            ans = arr[i][1];
        }
    }
    printf("%d",ans);
}