#include "bits/stdc++.h"

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    int a = a1*b2 + a2 * b1;
    int b = b1*b2;
    int g = gcd(a,b);
    cout << a/g << ' ' << b/g;
}