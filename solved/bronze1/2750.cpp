#include "stdio.h"
#include "vector"
#include "algorithm"
int main(void)
{
    int n , tmp;
    scanf("%d",&n);
    std::vector<int> arr;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&tmp);
        arr.push_back(tmp);
    }
    std::sort(arr.begin(),arr.end());
    for (int i = 0; i < n; ++i) {
        printf("%d\n",arr[i]);
    }
}