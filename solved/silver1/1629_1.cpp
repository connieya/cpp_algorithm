#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a, b, c, ans = 1;
    cin >> a >> b >> c;
    while (b > 0) {
        if (b % 2) {
            ans *= a;
            ans %= c;
        }
        a *= a;
        b /= 2;
        a %= c;
    }
    cout << ans;
}