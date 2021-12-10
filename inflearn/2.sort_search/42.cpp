#include "stdio.h"
#include "vector"
#include "algorithm"
int main(void)
{
    int n ,m , start =0, end , answer = -1;
    scanf("%d %d",&n,&m);
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    std::sort(arr.begin(),arr.end());
    end = n-1;
    while (start<=end){
        int mid = (start+end)/2;
        if (arr[mid] == m){
            answer = mid+1;
            break;
        }
        if(arr[mid] > m){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    printf("%d\n",answer);
}