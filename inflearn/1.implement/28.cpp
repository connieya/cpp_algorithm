#include "stdio.h";

int main(void)
{
    int n, i ,tmp , j , answer =0;
    scanf("%d",&n);
    for (i = 2; i <=n; ++i) {
        tmp = i;
        j = 2;
        while (tmp > 1){
            if(tmp % j == 0){
                if(j == 5) {
                    answer++;
                }
                tmp = tmp / j;
            }else {
                j++;
            }
        }
    }
    printf("%d",answer);
}