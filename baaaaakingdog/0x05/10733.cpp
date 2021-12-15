#include "stdio.h"

int stack[100000];
int pos;

int main(void) {
    int k, tmp, sum = 0;
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &tmp);
        tmp ? sum += stack[pos++] = tmp : sum -= stack[--pos];
    }
    printf("%d", sum);
}