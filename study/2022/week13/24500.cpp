#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

bool ispower2(ll n) {
    return (n & -n) == n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    ll m = 1;
    cin >> n;
    if (ispower2(n + 1)) {
        cout << 1 << '\n' << n;
    } else {
        while (m <= n) {
            m <<= 1;
        }
        cout << 2 << '\n' << m-1-n << '\n' << n;
    }

}