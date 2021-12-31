#include "stdio.h"

using ll = long long;

ll pow(ll a, ll b, ll c) {
    if (b == 1) {
        return a % c;
    }
    ll value = pow(a, b / 2, c);
    value = value * value % c;
    if (b % 2 == 0) {
        return value;
    } else {

        return value * a % c;
    }
}

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%lld", pow(a,b,c));
}