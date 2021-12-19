#include "stdio.h"

void recursive(int n) {
    if (n < 1) {
        return;
    }
    recursive(n - 1);
    printf("%d ", n);
}

int main() {
    int n;
    scanf("%d", &n);
    recursive(n);

}