#include "bits/stdc++.h"

using namespace std;

int parent[10001];

int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[a] = b;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    long long ans = 0;
    vector<pair<int, pair<int, int>>> graph;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int cost, a, b;
        cin >> a >> b >> cost;
        graph.push_back({cost, {a, b}});
    }
    sort(graph.begin(), graph.end());
    int len = graph.size();
    for (int i = 0; i < len; ++i) {
        int a = graph[i].second.first;
        int b = graph[i].second.second;
        if (find(a) != find(b)){
            Union(a,b);
            ans += graph[i].first;
        }
    }
    cout << ans;
}