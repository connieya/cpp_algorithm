#include "stdio.h"
#include "algorithm"

using namespace std;

int main(void)
{
    int n,x;
    scanf("%d %d",&n,&x);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    int ans = upper_bound(arr,arr+n,x) - lower_bound(arr,arr+n,x);
    printf("%d", !ans ? -1 : ans );
}