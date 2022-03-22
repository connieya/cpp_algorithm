#include "bits/stdc++.h"

typedef long long LL;
using namespace std;


LL pow(LL a, LL b, LL c) {
    if (b == 1) {
        return a % c;
    }

    if (b % 2 == 0) {
        LL num = pow(a, b / 2, c);
        return num*num % c;
    } else {
        LL num = pow(a,(b-1)/2,c);
        return ((num*num%c)*a) % c;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    LL a, b, c;
    cin >> a >> b >> c;
    cout << pow(a,b,c);
}