#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c;
    d = a ^ b;
    if (c % 2) {
        cout << d;
    } else {
        cout << a;
    }
}