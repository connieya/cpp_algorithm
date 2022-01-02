#include "stdio.h"

int num[201] = {};
int main(void)
{
    int n ,v , temp;
    scanf("%d",&n);
    while (n--){
        scanf("%d",&temp);
        num[temp+100]++;
    }
    scanf("%d",&v);
    printf("%d",num[v+100]);
}