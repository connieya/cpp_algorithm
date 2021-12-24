#include "stdio.h"

int arr[11];

int sum;
bool flag = false;

void dfs(int L , int n , int total){
    if (flag){
        return;
    }
    if (L == n) {
        if (total == sum-total){
            flag = true;
        }
        return;
    }
    dfs(L+1,n,total+arr[L]);
    dfs(L+1,n,total);
}

int main(void)
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    dfs(0,n,0);
    if (flag){
        printf("YES");
    }else {
        printf("NO");
    }
}