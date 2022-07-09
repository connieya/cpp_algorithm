#include "bits/stdc++.h"
using namespace std;

int n, m;

bool check(pair<int, int> &a, pair<int, int> &b) {
    if (a.first <= n && a.second <= m && b.first <= n && b.second <= m &&!(n-b.first < a.first && m-b.second < a.second)) return 1;
    if (a.first <= n && a.second <= m && b.second <= n && b.first <= m && !(n - b.second < a.first && m - b.first < a.second)) return 1;
    if (a.second <= n && a.first <= m && b.first <= n && b.second <= m && !(n - b.first < a.second && m - b.second < a.first)) return 1;
    if (a.second <= n && a.first <= m && b.second <= n && b.first <= m && !(n - b.second < a.second && m - b.first < a.first)) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, ans = 0;
    cin >> n >> m >> t;
    vector<pair<int, int>> v;
    for (int i = 0; i < t; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    for (int i = 0; i < t; ++i) {
        for (int j = i + 1; j < t; ++j) {
            if (check(v[i], v[j])) {
                ans = max(ans, v[i].first * v[i].second + v[j].first * v[j].second);
            }
        }
    }
    cout << ans << '\n';

}