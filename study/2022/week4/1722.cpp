﻿#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int n, k;
int arr[21];
ll factorial[21] = {1,};
bool check[21];

void solve1() {
    ll idx;
    cin >> idx;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (check[j]) continue;
            if (factorial[n - (i + 1)] < idx) {
                idx -= factorial[n - (i + 1)];
            } else {
                ans[i] = j;
                check[j] = true;
                break;
            }
        }
    }
    for (auto a: ans) {
        cout << a << ' ';
    }
}

void solve2() {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < arr[i]; ++j) {
            if (!check[j]) {
                ans += factorial[n - (i + 1)];
            }
        }
        check[arr[i]] = true;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= 20; i++) {
        factorial[i] = factorial[i - 1] * i;
    }

    cin >> n >> k;
    if (k == 1) {
        solve1();
    } else {
        solve2();
    }
}