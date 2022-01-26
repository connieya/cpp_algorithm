#include "stdio.h"
#include "algorithm"

using namespace std;
int arr[8];
int n,m;
int answer[8];

void dfs(int L,int start) {
    if (L ==m){
        for (int i = 0; i < m; ++i) {
            printf("%d ",answer[i]);
        }
        printf("\n");
        return;
    }
    for (int i = start; i < n; ++i) {
            answer[L] = arr[i];
            dfs(L+1,i);
        }

    }

int main(void)
{
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    sort(arr, arr+n);
    dfs(0,0);
}