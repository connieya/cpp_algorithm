#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, s = 3, k = 4;
    cin >> n;
    while (n > s) {
        s = s * 2 + k;
        k++;
    }
    k -= 1;
    while (1) {
        long long t = (s - k) / 2;
        if (t >= n) {
            s = t;
            k--;
        } else if (t + k < n) {
            n -= t + k;
            k--;
            s = t;
        } else {
            n -= t;
            break;
        }
    }
    if (n == 1) {
        cout << "m";
    } else {
        cout << "o";
    }
}