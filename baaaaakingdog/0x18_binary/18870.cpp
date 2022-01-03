#include "stdio.h"
#include "algorithm"
#include "vector"
using namespace std;
int main(void)
{
    int n;
    scanf("%d",&n);
    int arr[n] , tmp[n];
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
        tmp[i] = arr[i];
    }
    sort(tmp,tmp+n);
    for (int i = 0; i < n; ++i) {
        if (i==0 || tmp[i-1] != tmp[i]){
            ans.push_back(tmp[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin());
    }
}