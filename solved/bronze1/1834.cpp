#include "stdio.h"

int main() {
    long long n;
    long long sum = 0;
    scanf("%lld", &n);
    long long value = n + 1;
    for (int i = 1; i <= (n- 1); i++) {
        sum += value * i;
    }
    printf("%lld", sum);
}