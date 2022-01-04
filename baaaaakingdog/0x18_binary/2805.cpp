#include "stdio.h"
#include "algorithm"

using namespace std;
int main(void)
{
    int n,tree,ans=0;
    scanf("%d %d",&n,&tree);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    long long lt =0;
    long long rt = arr[n-1];
    while (lt<=rt){
        int len = (lt+rt)/2;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] > len){
                sum += arr[i]-len;
            }
        }
        if (sum >= tree) {
            ans = len;
            lt = len+1;
        }else{
            rt = len-1;
        }
    }
    printf("%d",ans);
}