﻿#include "bits/stdc++.h"

using namespace std;

int arr[2001];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int v = arr[i]+arr[j];
            int lt = lower_bound(arr+j+1,arr+n,v)-arr;
            int rt = upper_bound(arr+j+1,arr+n,v)-arr;
            cout << v << ' ' << rt-lt <<'\n';
            ans += rt-lt;
        }
    }
    cout << ans;
}