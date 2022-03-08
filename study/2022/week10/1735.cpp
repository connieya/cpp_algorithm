#include "bits/stdc++.h"

using namespace std;


pair<int, int> solve(int a, int b) {
    pair<int, int> fraction;
    int v = 2;
    while (a >= v && b >= v) {
        if (a % v == 0 && b % v == 0) {
            a = a / v;
            b = b / v;
        } else {
            v++;
        }
    }
    fraction.first = a;
    fraction.second = b;
    return fraction;
}

int gcd(int a, int b) {
    if (b==0) return a;
    return gcd(b,a%b);

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    pair<int, int> f1 = solve(a1, b1);
    pair<int, int> f2 = solve(a2, b2);
    pair<int, int> ans = solve(f1.first * f2.second + f2.first * f1.second, f1.second * f2.second);
    cout << ans.first << ' ' << ans.second;
}