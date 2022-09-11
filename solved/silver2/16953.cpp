#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a, b;
    cin >> a >> b;
    for (int i = 1; a <= b; ++i) {
        if (a == b) {
            cout << i;
            return 0;
        }
        if (b % 2 == 0) {
            b /= 2;
        } else if (b % 10 == 1) {
            b = (b - 1) / 10;
        } else {
            break;
        }
    }
    cout << -1;
}