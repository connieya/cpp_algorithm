#include "stdio.h"
int a,b;
int main()
{
    scanf("%d",&a);
    while (a>9){
        a = a%10 < 5 ? a/10 : a/10+1;
        b++;
    }
    while (b--){
        a*=10;
    }
    printf("%d",a);
}