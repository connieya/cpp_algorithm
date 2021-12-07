#include "stdio.h"

int main(void) {
    int n, i, pre, now, cnt, max;
    scanf("%d", &n);
    scanf("%d", &pre);
    cnt = 1;
    max = 1;
    for (i = 1; i < n; ++i) {
        scanf("%d", &now);
        if (now >= pre) {
            cnt++;
        } else {
            cnt = 1;
        }
        if (cnt > max) {
            max = cnt;
        }
        pre = now;
    }
    printf("%d", max);

}