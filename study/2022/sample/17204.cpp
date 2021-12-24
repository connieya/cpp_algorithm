#include "stdio.h"

int people[150];

int main(void)
{
    int n,k ,result, cnt =1;

    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&people[i]);
    }
    result = people[0];
    while (result != k){
        result = people[result];
        cnt++;
        if (cnt > n){
            cnt = -1;
            break;
        }
    }
    printf("%d",cnt);
}