#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    int minute = b+c;
    a += minute/60;
    minute %= 60;
    a > 23 ? a -= 24 : a;
    cout << a << ' ' << minute;

}