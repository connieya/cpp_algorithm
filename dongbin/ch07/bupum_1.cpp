#include "stdio.h"
#include "algorithm"

using namespace std;

int binarySearch(int arr[], int lt , int rt , int target) {
    while (lt <= rt) {
        int mid = (lt + rt) /2;
        if (arr[mid] == target) return mid;
        if (arr[mid] > target) {
            rt= mid-1;
        }else {
            lt = mid+1;
        }
    }
    return 0;
}

int main(void)
{
    int n ,m , tmp;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    scanf("%d",&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d",&tmp);
        if (binarySearch(arr,0,n-1,tmp)) {
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }

}