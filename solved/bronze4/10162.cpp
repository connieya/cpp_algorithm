#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    if (t % 10) {
        cout << -1;
    } else {
        cout << t / 300 << ' ' << t % 300 / 60 << ' ' << t % 300 % 60 / 10;
    }
}