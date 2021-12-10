#include "stdio.h"

int gcd(int a, int b){
    return b==0 ?a : gcd(b,a%b);
}

int main()
{
    int t,a,b;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&a,&b);
        printf("%d\n",a*b/ gcd(a,b));
    }
}