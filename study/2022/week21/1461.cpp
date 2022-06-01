#include "bits/stdc++.h"

#define g(v) (v.size() ? v.back() : 0)

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    vector<int> w;
    int n, m, t, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        (t < 0 ? v : w).push_back(abs(t));
    }
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    for (int i = v.size() - 1; i >= 0; i += m) {
        ans += v[i];
    }
    for (int i = w.size() - 1; i >= 0; i -= m) {
        ans += w[i];
    }
    ans <<= 1;
    cout << ans - max(g(w), g(v));
}