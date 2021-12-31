#include "stdio.h"

using ll = long long;
ll big = 1e9 + 7;

ll pow(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    ll value = pow(a, b / 2);
    value = value * value % big;
    if (b % 2 == 0) {
        return value;
    } else {
        return value * a % big;
    }
}

int main(void) {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (n == 1) {
            printf("1\n");
        } else {
            printf("%lld\n", pow(2, n - 2));
        }
    }
}
