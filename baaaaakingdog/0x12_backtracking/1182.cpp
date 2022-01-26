#include "stdio.h"

int arr[20];
int n, s;
int ans;

void dfs(int L , int sum) {
    if (L == n) {
        if (sum == s){
            ans++;
        }
        return;
    }
    dfs(L+1 , sum+arr[L]);
    dfs(L + 1 , sum);
}

int main(void) {
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    dfs(0,0);
    if (!s){
        ans--;
    }
    printf("%d",ans);
}