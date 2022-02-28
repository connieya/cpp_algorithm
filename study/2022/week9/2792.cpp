#include "bits/stdc++.h"

using namespace std;

int j[300001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    long long left = 1;
    long long right = 0;
    for (int i = 0; i < m; ++i) {
        cin >> j[i];
        if (j[i] > right) {
            right = j[i];
        }
    }
    long long res = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long st = 0;
        for (int i = 0; i < m; ++i) {
            st += j[i] / mid;
            if ((j[i] % mid) != 0) st++;
        }
        if (st <= n) {
            right = mid - 1;
            res = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << res;
}