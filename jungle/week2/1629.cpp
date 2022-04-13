#include "bits/stdc++.h"

typedef long long ll;
using namespace std;


ll func(ll a, ll b, ll c) {
    if (b == 1) {
        return a % c;
    }
    ll res = func(a, b / 2, c);
    res = res*res%c;
    if (b % 2 == 1) {
        return res*a%c;
    } else {
        return res;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    cout << func(a, b, c);
}