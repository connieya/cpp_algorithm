#include "bits/stdc++.h"

using namespace std;

int d[1000000];

int fn(int n) {
    if (n == 1) {
        return 0;
    }
    if (d[n] > 0) return d[n];
    d[n] = fn(n-1) + 1;

    if (n % 3 == 0) {
        int tmp = fn(n / 3) +1;
        if (d[n] > tmp) {
            d[n] = tmp;
        }
    }
    if (n % 2 == 0) {
        int tmp = fn(n / 2) +1;
        if (d[n] > tmp) {
            d[n] = tmp;
        }
    }
    return d[n];
}

int main() {
    int n;
    cin >> n;
    cout << fn(n);
}