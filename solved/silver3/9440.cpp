#include "bits/stdc++.h"

using namespace std;

int arr[15];

int solve(int n) {
    sort(arr, arr + n);
    for (int i = 0; i < n; ++i) {
        if (!arr[i]) continue;
        swap(arr[0], arr[i]);
        swap(arr[1], arr[i + 1]);
        break;
    }

    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            a = a * 10 + arr[i];
        } else {
            b = b * 10 + arr[i];
        }
    }
    return a + b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1) {
        int n;
        cin >> n;
        if (!n) break;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << solve(n) << '\n';
    }
}