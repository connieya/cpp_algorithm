#include "stdio.h"


int recursive(int n) {
    if (n == 0) return 0;
    return n + recursive(n-1);
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d",  recursive(n));
}