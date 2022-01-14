#include "bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long l, p, v;
    int i = 1;
    while (1) {
        cin >> l >> p >> v;
        if (!l && !p && !v) break;
        int option = (v%p) > l ? l : v%p;
        cout << "Case " << i++ << ": " << (v / p) * l + option << '\n';
    }
}