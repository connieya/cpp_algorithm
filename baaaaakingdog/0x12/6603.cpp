#include "stdio.h"
#include "algorithm"
int k;
int arr[13];
int ans[13];


int main(void)
{
    while (1) {
        scanf("%d",&k);
        if (!k){
            break;
        }
        for (int i = 0; i < k; ++i) {
            scanf("%d",&arr[i]);
        }
        for (int i = 6; i < k; ++i) {
            ans[i] = 1;
        }
        do {
            for (int i = 0; i < k; ++i) {
                if (!ans[i]){
                    printf("%d ",arr[i]);
                }
            }
            printf("\n");
        } while (std::next_permutation(ans,ans+k));
        printf("\n");

    }
}