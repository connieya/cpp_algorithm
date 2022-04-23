#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> p;


vector<p> v;

bool comp(const p &a, p &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }
    sort(v.begin(), v.end(), comp);
//    for (auto t: v) {
//        cout << t.first << ' ' << t.second << '\n';
//    }
    int len = v.size();
    int prev = v[0].second;
    for (int i = 1; i < len; ++i) {
        int cur = v[i].first;
        if (cur >= prev) {
            ans++;
            prev = v[i].second;
        }
    }
    cout << ans;
}