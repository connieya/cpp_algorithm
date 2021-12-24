#include "stdio.h"

int map[51][51];
int main(void)
{
    int n ,k,a,b,c;
    scanf("%d %d",&n,&k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %d %d",&a,&b,&c);
        map[a][b] = c;
    }
}