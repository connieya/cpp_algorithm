#include "stdio.h"
int main() {
    int n, m, sum = 0, min = 2145606066;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i * i <= m; i++) {
        if (i * i >= n) {
                sum += i*i;
            min = (sum > min) ? min : sum;
        }
    }
    if (sum == 0) {
        printf("%d", -1);
    } else {
        printf("%d\n", sum);
        printf("%d\n", min);
    }
}