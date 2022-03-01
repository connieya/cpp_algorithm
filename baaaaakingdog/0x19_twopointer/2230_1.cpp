#include "bits/stdc++.h"

using namespace std;

int arr[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int max = arr[n-1];
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (arr[i]+m > max) continue;
        int idx = lower_bound(arr+i,arr+n,arr[i]+m)-arr;
        if (arr[idx]-arr[i] >= m){
            ans = min(ans , arr[idx]-arr[i]);
        }
        if (arr[idx]-arr[i] == m) break;
    }
    cout << ans;
}