#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, n = 0;
    cin >> m;
    while (m--) {
        string op;
        int k;
        cin >> op;
        if (op == "add") cin >> k , n |= 1 << k;
        else if (op == "remove") cin >> k, n &= ~(1 << k);
        else if (op == "check") cin >> k, cout << bool(n & 1 << k) << '\n';
        else if (op == "toggle") cin >> k, n ^= 1 << k;
        else if (op == "all") n = -1;
        else n = 0;
    }
}