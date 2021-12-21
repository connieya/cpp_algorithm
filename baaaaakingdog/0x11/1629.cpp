#include "stdio.h"

using ll = long long;

ll POW(ll a, ll b, ll m) {
    if (b == 1) return a % m;
    ll val = POW(a, b / 2, m);
    val = val * val % m;
    if (b % 2 == 0) return val;
    return val * a & m;
}

int main(void) {
    int a, b, c;
    ll ans = 1;
    scanf("%d %d %d", &a, &b, &c);
    while (b--) {
        printf("%d  ",ans*a);
        ans = (ans * a) % c;
        printf("%d\n",ans);
    }
    printf("%lld", ans);
}