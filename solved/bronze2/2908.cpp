#include "bits/stdc++.h"

using namespace std;

int reverse(int n) {
    return  n/100 + n%10*100 + (n/10)%10*10;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    cout << (reverse(a) > reverse(b)  ? reverse(a) : reverse(b));
}