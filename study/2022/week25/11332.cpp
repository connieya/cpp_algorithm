﻿#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
#define MAX 100000000

const string PASS = "May Pass.\n";
const string FAIL = "TLE!\n";

ll _pow(ll num, ll cnt) {
    if (cnt <= 1) return num;
    ll res = _pow(num, cnt / 2);
    if (cnt % 2) {
        return num * res * res;
    }
    return res * res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    string s;
    ll n, t, l, sum;
    cin >> m;
    while (m--) {
        cin >> s >> n >> t >> l;
        if (s == "O(N)") {
            sum = n * t;
            if (sum <= l * MAX) {
                cout << PASS;
            } else {
                cout << FAIL;
            }
        } else if (s == "O(2^N)") {
            if (n >= 30) {
                cout << FAIL;
            } else {
                sum = (ll) pow(2, n) * t;
                if (sum <= l * MAX) {
                    cout << PASS;
                } else {
                    cout << FAIL;
                }
            }

        } else if (s == "O(N!)") {
            if (n >= 13) {
                cout << FAIL;
            } else {
                sum = t;
                for (ll i = 1; i <= n; i++) {
                    sum *= i;
                }
                if (sum <= l * MAX) {
                    cout << PASS;
                } else {
                    cout << FAIL;
                }
            }

        } else if (s == "O(N^3)") {
            if (n >= 1001) {
                cout << FAIL;
            } else {
                sum = (n * n * n * t);
                if (sum <= (l * MAX)) {
                    cout << PASS;
                } else {
                    cout << FAIL;
                }
            }

        } else if (s == "O(N^2)") {
            if (n >= 31623) {
                cout << FAIL;
            } else {
                sum = n * n * t;
                if (sum <= l * MAX) {
                    cout << PASS;
                } else {
                    cout << FAIL;
                }
            }
        }
    }
}