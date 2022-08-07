﻿#include "bits/stdc++.h"

using namespace std;

int arr[100001];

int solve(int n) {
    int ans = 100005;
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            int change = 0;
            if (i != 0) change++;
            if (j != 0) change++;
            int first = arr[0] + i;
            int an = arr[1] + j;
            int diff = an - first;
            bool flag = false;
            for (int k = 2; k < n; ++k) {
                an += diff;
                if (an == arr[k]) continue;

                if (an == arr[k] + 1) change++;
                else if (an == arr[k] - 1) change++;
                else {
                    flag = true;
                }
                if (flag) break;
            }
            if (flag) continue;
            if (change < ans) {
                ans = change;
            }
        }
    }
    return (ans == 100005) ? -1 : ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << solve(n);
}