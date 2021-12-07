#include "stdio.h"

int main() {
    int a, b, n;
    scanf("%d %d %d",&a, &b ,&n);
    int result = a%b;
    for (int i=0; i<n-1; i++){
        result *= 10;
        result %= b;
    }
    result *= 10;
    printf("%d",result/b);
}