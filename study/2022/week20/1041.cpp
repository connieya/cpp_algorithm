#include "bits/stdc++.h"

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, ans = 0;
    cin >> n;
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (n == 1) {
        cout << a + b + c + d + e + f - max({a, b, c, d, e, f});
        exit(0);
    }
    ll t1 = min({a, b, c, d, e, f});
    ll t2 = min({a + b, a + c, a + d, a + e, f + b, f + c, f + d, f + e, b + c, c + e, e + d, d + b});
    ll t3 = min({a + b + c, a + c + e, a + e + d, a + d + b, f + b + c, f + c + e, f + e + d, f + d + b});
    ans += ((n - 2) * (n - 2) * 5 + (n - 2) * 4) * t1;
    ans += ((n - 2) * 8 + 4) * t2;
    ans += 4 * t3;
    cout << ans << '\n';
}