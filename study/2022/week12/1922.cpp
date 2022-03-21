#include "bits/stdc++.h"

using namespace std;

int parent[1001];

int find(int a);

bool Union(int a, int b);

int find(int a) {
    if (a == parent[a]) {
        return a;
    }
    return parent[a] = find(parent[a]);
}

bool Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    parent[a] = b;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, cost;
    vector<pair<int, pair<int, int>>> V;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> cost;
        V.push_back({cost, {a, b}});
    }
    int cnt = 0, ans = 0, len = V.size();
    sort(V.begin(), V.end());
    for (int i = 0; i < len; ++i) {
        int a = V[i].second.first;
        int b = V[i].second.second;
        if (a == b) continue;
        if (Union(a, b)) {
            ans += V[i].first;
            if (++cnt == n-1) break;
        }
    }
    cout << ans;
}