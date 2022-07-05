#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, t, ans = 0, x, y;
    cin >> n >> m >> t;
    vector<pair<int, int>> v;
    while (t--) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    cin >> x >> y;
    for (int i = 0; i < v.size(); ++i) {
        auto cur = v[i];
        int a = cur.first;
        int b = cur.second;
        if (a == x) {
            ans += abs(b - y);
        } else if (x == 1 || x == 2) {

        } else if (x == 3 || x == 4) {

        }
    }
}