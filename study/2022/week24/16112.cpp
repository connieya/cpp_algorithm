﻿#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

ll arr[300001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    ll sum = 0;
    for (int i = 1; i < n; i++) {
        sum += arr[i] * min(i, k);
    }
    cout << sum;
}