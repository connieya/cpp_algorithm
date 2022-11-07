#include "bits/stdc++.h"

using namespace std;

int dp[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, a, b;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        for (int j = k; j >= a;--j) {
            dp[j] = max(dp[j], dp[j - a] + b);
        }
    }
    cout << dp[k];
}