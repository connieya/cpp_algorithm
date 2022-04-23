#include "bits/stdc++.h"

using namespace std;

int total, n, res = -1;
vector<pair<int, int>> pipe;

void dfs(int L, int len, int vol) {
    if (len > total) return;
    if (L == pipe.size()) {
        if (total == len) {
            res = max(res, vol);
        }
        return;
    } else {
        dfs(L + 1, len + pipe[L].first, min(vol, pipe[L].second));
        dfs(L + 1, len, vol);

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> total >> n;
    for (int i = 0; i < n; ++i) {
        int l, v;
        cin >> l >> v;
        pipe.push_back({l, v});
    }
    dfs(0, 0, 1e4);
    cout << res;

}