#include "bits/stdc++.h"

using namespace std;

int l, n, res = -1;
vector<pair<int, int>> v;

int dfs(int L, int start, int vm) {
    if (L == l) {
        return vm;
    }

    for (int i = start; i < v.size(); ++i) {
        int len = v[i].first;
        int volume = v[i].second;
        if (len + L > l) continue;
        volume = min(volume, vm);
        res =max(dfs(len + L, i + 1, volume),res);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> l >> n;
    for (int i = 0; i < n; ++i) {
        int len, vol;
        cin >> len >> vol;
        v.push_back({len, vol});
    }
    cout <<dfs(0, 0, 1e3);
}