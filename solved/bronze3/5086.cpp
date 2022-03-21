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
    int a, b;
    while (1) {
        cin >> a >> b;
        if (a + b == 0) break;
        string answer;
        answer = (a % b) ? (b % a) ? "neither" : "factor" : "multiple";
        cout << answer << '\n';
    }
}