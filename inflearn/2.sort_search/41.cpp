#include "stdio.h"

int main(void) {
    int a, b = 1, cnt = 0, tmp, i;
    scanf("%d", &a);
    tmp = a;
    a--;
    while (a>0){
        b++;
        a= a-b;
        if(a%b ==0) {
            for (i=1; i<b; i++){
                printf("%d + ",(a/b)+i);
            }
            printf("%d = %d\n",(a/b)+i,tmp);
            cnt++;
        }

    }
    printf("%d",cnt);
}