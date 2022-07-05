#include "bits/stdc++.h"

using namespace std;

struct Info {
    int start, end, cnt;

    bool operator<(Info i) {
        if (i.end == end) {
            return start < i.start;
        }
        return end < i.end;
    }

};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, m;
    vector<Info> v;
    cin >> n >> k >> m;
    v.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> v[i].start >> v[i].end >> v[i].cnt;
    }
    sort(v.begin(), v.end());
    int ans = 0;



}