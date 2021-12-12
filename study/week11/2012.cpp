#include "stdio.h"
#include "vector"
#include "algorithm"
#include "stdlib.h"
int main(void)
{
    int n , rank;
    long sum = 0 ;
    scanf("%d",&n);
    std::vector<int> koi;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&rank);
        koi.push_back(rank);
    }
    std::sort(koi.begin(),koi.end());
    for (int i = 0; i < n; ++i) {
        sum += abs(koi[i]- (i+1));
    }
    printf("%ld",sum);
}