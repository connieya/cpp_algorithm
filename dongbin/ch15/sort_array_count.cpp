#include "stdio.h"
#include "algorithm"

using namespace std;

int lowerBound(int arr[],int lt ,int rt ,int target){
    while (lt < rt){
        int mid = (lt + rt) /2;
        if (arr[mid] >= target) {
            rt = mid;
        } else{
            lt = mid+1;
        }
    }
    return rt;
}

int upperBound(int arr[],int lt ,int rt ,int target){
    while (lt < rt){
        int mid = (lt + rt) /2;
        if (arr[mid] > target) {
            rt = mid;
        } else{
            lt = mid+1;
        }
    }
    return rt;
}

int main(void)
{
    int n,x;
    scanf("%d %d",&n,&x);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    int ans = upperBound(arr,0,n,x)- lowerBound(arr,0,n,x);
    printf("%d", !ans ? -1 : ans );
}