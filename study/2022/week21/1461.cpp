#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, t = 0, ans = 0;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i] < 0) {
            t++;
        }
    }
    sort(v.begin(), v.end());
    for (int i = n - 1; i >= t; i -= m) {
        ans += v[i];
    }
    for (int i = 0; i < t; i += m) {
        ans += abs(v[i]);
    }
    ans <<= 1;
    cout << ans - max(abs(v[0]), abs(v[n - 1]));
}