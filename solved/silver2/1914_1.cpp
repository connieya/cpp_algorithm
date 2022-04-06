#include "bits/stdc++.h"

using namespace std;

unsigned long long recur(int n) {
    if (n <= 1) return 2;
    unsigned long long pow = recur(n / 2);
    if (n % 2) {
        return pow * pow * 2;
    } else {
        return pow * pow;
    }
}

void hanoi(int n, int a, int b) {
    if (n == 1) {
        cout << a << ' ' << b << '\n';
        return;
    }

    hanoi(n - 1, a, 6 - a - b);
    cout << a << ' ' << b << '\n';
    hanoi(n - 1, 6 - a - b, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << recur(n) - 1 << '\n';
    if (n <= 20) {
        hanoi(n, 1, 3);
    }
}