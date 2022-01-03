#include "stdio.h"
#include "algorithm"
#include "vector"
using namespace std;
int main(void)
{
    int n , ans = -1;
    scanf("%d",&n);
    int arr[n];
    vector<int> two;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            two.push_back(arr[i]+arr[j]);
        }
    }
    for (int i = 0; i < two.size(); ++i){
        for (int j = 0; j < n; ++j) {
            int sum = two[i]+arr[j];
            if (binary_search(arr,arr+n,sum)){
                ans = max(ans,sum);
            }
        }
    }
    printf("%d",ans);
}