﻿#include "bits/stdc++.h"

using namespace std;

int arr[1000];
int lis[1000];
int lds[1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    lis[0] = 1;
    for (int i = 1; i < n; ++i) {
        lis[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && lis[j] + 1 > lis[i]) {
                lis[i] = lis[j] + 1;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        lds[i] = 1;
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j] && lds[j] + 1 > lds[i]) {
                lds[i] = lds[j] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, lds[i] + lis[i] - 1);
    }
    cout << ans;
}