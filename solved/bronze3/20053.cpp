﻿#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mn = 1e6 + 1, mx = -1000001, value;
        for (int i = 0; i < n; ++i) {
            cin >> value;
            if (value > mx) {
                mx = value;
            }
            if (value < mn) {
                mn = value;
            }
        }
        cout << mn << " " << mx << '\n';
    }
}