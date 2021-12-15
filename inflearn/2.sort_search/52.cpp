#include "stdio.h"

#define min(a, b) a > b ? b : a
int a[1501];

int main(void) {
    int n, p2 = 1, p3 = 1, p5 = 1, pos = 2, min = 100;
    a[1] = 1;
    scanf("%d", &n);
    while (pos <= n) {
        min = min(a[p2]*2, a[p3]*3);
        min = min(min,a[p5]*5);
        a[pos] = min;
        if(min == a[p2]*2) p2++;
        if(min == a[p3]*3) p3++;
        if(min == a[p5]*5) p5++;
        pos++;

    }
    printf("%d",a[n]);
}