#include "bits/stdc++.h"

using namespace std;

int arr[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + m);
    int cnt = 0;
    for (int i = m - 1; i >= 0; --i) {
        if (n == 0) break;
        cnt += (n / arr[i]);
        n = n % arr[i];
    }
    if (n == 0) {
        cout << cnt;
    } else {
        cout << -1;
    }
}