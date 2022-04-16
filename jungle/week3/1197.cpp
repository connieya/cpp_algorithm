#include "bits/stdc++.h"

using namespace std;

vector<pair<int, pair<int, int>>> graph;

int parent[10001];

int find(int a);

void Union(int a, int b);

int find(int a) {
    if (a == parent[a]) {
        return a;
    }
    return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[a] = b;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int v, e, cnt = 0, ans = 0;
    cin >> v >> e;
    for (int i = 1; i <= v; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < e; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph.push_back({cost, {from, to}});
    }
    sort(graph.begin(), graph.end());
    for (int i = 0; i < graph.size(); ++i) {
        int a = graph[i].second.first;
        int b = graph[i].second.second;
        if (find(a) != find(b)) {
            ans += graph[i].first;
            cnt++;
            Union(a, b);
        }
        if (cnt == v - 1) break;
    }
    cout << ans;


}