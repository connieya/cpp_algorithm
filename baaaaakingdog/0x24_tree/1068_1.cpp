#include "stdio.h"

int n;
int parent[51];
int child[51];

void dfs(int s){

}

int main(void)
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&parent[i]);
        if (parent[i] != -1) {
            child[parent[i]]++;
        }
    }
    int m;
    scanf("%d",&m);
    dfs(m);
    int ans = 0;
}