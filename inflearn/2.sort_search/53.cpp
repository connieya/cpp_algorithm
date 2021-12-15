#include "stdio.h"

int stack[100];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    char str[20] = "0123456789ABCDEF";
    while (n) {
        push(n % k);
        n /= k;
    }
    while (top != -1) {
        printf("%c", str[pop()]);
    }
    return 0;
}