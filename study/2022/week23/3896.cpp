#include "bits/stdc++.h"

using namespace std;

bool isPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, v;
    cin >> t;
    while (t--) {
        cin >> v;
        int x = v, y = v;
        while (!isPrime(x)) x--;
        while (!isPrime(y)) y++;
        cout << y - x << '\n';
    }
}