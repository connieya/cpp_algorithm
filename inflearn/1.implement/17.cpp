#include "stdio.h"
int main()
{
    int n;
    scanf("%d",&n);
    while (n--){
        int num , answer;
        scanf("%d %d",&num,&answer);
        if(answer == (num*(num+1)) /2){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}