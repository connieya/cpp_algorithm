#include "stdio.h"
#include "algorithm"
int a[1000000];
int main(void)
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    std::sort(a,a+n);
    for (int i = 0; i < n; ++i) {
        printf("%d\n",a[i]);
    }
}