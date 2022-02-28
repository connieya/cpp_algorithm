#include "bits/stdc++.h"

using namespace std;

int arr[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int value = arr[i] + arr[j];
            int lt = lower_bound(arr+j+1, arr + n, -value) - arr;
            int rt = upper_bound(arr+j+1, arr + n, -value) - arr;
            ans += rt - lt;

        }
    }
    cout << ans;


}