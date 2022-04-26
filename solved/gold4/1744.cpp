#include "bits/stdc++.h"

using namespace std;

int dp[51];

int solve(vector<int> v) {
    int len = v.size();
    dp[0] = v[0];
    for (int i = 1; i < len; ++i) {
        int t1 = (i > 1 ? dp[i - 2] : 0) + v[i - 1] * v[i];
        int t2 = dp[i - 1] + v[i];
        dp[i] = max(t1, t2);
    }
    return dp[v.size() - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << solve(v);
}