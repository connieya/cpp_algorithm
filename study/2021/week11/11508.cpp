#include "stdio.h"
#include "vector"
#include "algorithm"
int main(void)
{
    int n , cnt =0;
    scanf("%d",&n);
    std::vector<int> arr(n);
    int sum =0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    std::sort(arr.begin(),arr.end());
    for (int i = n-1; i >=0 ; --i) {
        cnt++;
        if(cnt==3){
            sum -= arr[i];
            cnt = 0;
        }
    }
    printf("%d",sum);

}