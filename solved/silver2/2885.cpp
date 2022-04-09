#include "bits/stdc++.h"

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    int n = 1;
    while ((1 << n) < k) {
        n++;
    }

    cout << (1 << n) << ' ' << __builtin_ctz((1<<n))-__builtin_ctz(k);
}