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
    int r, g;
    cin >> r >> g;
    int gcd_ = gcd(r, g);
    int idx = 1;
    while (idx * idx < gcd_) {
        if (gcd_ % idx == 0) {
            cout << idx << " " << r / idx << " " << g / idx << '\n';
            cout << gcd_ / idx << " " << r / (gcd_ / idx) << " " << g / (gcd_ / idx) << '\n';
        }
        idx++;
    }
    if (idx * idx == gcd_) {
        cout << idx << " " << r / idx << " " << g / idx << '\n';
    }


}