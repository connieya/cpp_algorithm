#include "stdio.h"
#include "algorithm"

using namespace std;

int main(void)
{
    int n,m,tmp;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    scanf("%d",&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d",&tmp);
        printf("%d ", binary_search(arr,arr+n,tmp));
    }
}