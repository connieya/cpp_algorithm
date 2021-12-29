#include "stdio.h"
#include "algorithm"
int arr[10000];
int map[10000];

int main(void)
{
    int n,ans=0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    for (int i = 3; i < n; ++i) {
        map[i] = 1;
    }
    do {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (!map[i]){
                sum += arr[i];
            }
        }
        if (sum == 0){
            ans++;
        }
    } while (std::next_permutation(map,map+n));
    printf("%d",ans);
}