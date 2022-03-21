#include "bits/stdc++.h"

using namespace std;

long long gcd(long long a, long long b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a, b;
    cin >> a >> b;
    long long g = gcd(a,b);
    cout << a*b/g;
}