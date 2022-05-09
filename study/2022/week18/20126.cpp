#include "bits/stdc++.h"

using namespace std;

vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, s, x, y;
    cin >> n >> m >> s;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    int len = v.size();
    int prev_s = v[0].first;
    int time_s = v[0].second;
    if(m <= prev_s){
        cout << 0;
        exit(0);
    }
    for (int i = 1; i < len; ++i) {
        int start = v[i].first;
        int time = v[i].second;
        if (prev_s + time_s + m <= start) {
            cout << prev_s + time_s;
            exit(0);
        }
        prev_s = start;
        time_s = time;
    }
    if (prev_s + time_s + m <= s) {
        cout << prev_s + time_s;
    } else {
        cout << -1;
    }
}