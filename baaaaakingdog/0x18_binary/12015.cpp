#include "bits/stdc++.h"

using namespace std;

int arr[1000002];
int dp[1000002];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, size = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    dp[size] = arr[1];
    for (int i = 2; i <= n; ++i) {
        if (arr[i] > dp[size]) {
            size++;
            dp[size] = arr[i];
            continue;
        }
        int it = lower_bound(dp + 1, dp + size + 1, arr[i]) - dp;
        dp[it] = arr[i];
    }
    cout << size;
}

