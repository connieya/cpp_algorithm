#include "bits/stdc++.h"

using namespace std;

int unf[1000];
vector<pair<int ,pair<int ,int>>> edges;

int find(int a);

void Union(int a, int b);

int find(int a) {
    if (a == unf[a]) {
        return a;
    }
    return unf[a] = find(unf[a]);
}

void Union(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    unf[aa] = bb;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        unf[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int a , b ,c;
        cin >> a >> b >> c;
        edges.push_back({c, {a,b}});
    }
    sort(edges.begin() , edges.end());
    int ans = 0;
    for (int i = 0; i < edges.size(); ++i) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        a = find(a);
        b = find(b);
        if (a != b) {
            ans += cost;
            Union(a,b);
        }
    }
    cout << ans;
}