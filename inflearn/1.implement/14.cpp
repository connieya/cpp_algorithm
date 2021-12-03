#include "stdio.h"

bool isPrime[100001];

int reverse(int x) {
    int res = 0;
    while (x > 0) {
        res = res*10 + x%10;
        x /= 10;
    }
    return res;
}

int main() {
    isPrime[1] = true;
    for (int i = 2; i * i <= 100000; i++) {
        if (isPrime[i]) {
            continue;
        }
        for (int j = i + i; j <= 100000; j += i) {
            isPrime[j] = true;
        }
    }

    int n = 0, tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int input = 0;
        scanf("%d", &input);
        tmp = reverse(input);
        if (!isPrime[tmp]) {
            printf("%d ", tmp);
        }
    }

}