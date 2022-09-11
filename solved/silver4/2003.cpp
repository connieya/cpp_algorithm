#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int sum = 0, lt = 0, rt = 0, ans = 0;
    int arr[10001] = {0,};
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    while (rt < n) {
        if (sum < m) {
            sum += arr[rt++];
        } else {
            if (sum == m) ans++;
            sum -= arr[lt++];
        }
    }
    while (sum >= m && lt < n) {
        if (sum == m) ans++;
        sum -= arr[lt++];
    }
    cout << ans;
}