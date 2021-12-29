#include "stdio.h"
#include "algorithm"

using namespace std;
long long arr[100000];

int main(void)
{
    int n ;
    long long cnt =0, max =-1 , ans = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld",&arr[i]);
    }
    sort(arr,arr+n);
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] == arr[i+1]){
            cnt++;
        }else{
            if (cnt > max) {
                max = cnt;
                ans = arr[i];
            }
            cnt= 0;
        }
    }
    if (cnt > max){
        ans = arr[n-1];
    }
    printf("%lld",ans);
}