#include "bits/stdc++.h"

using namespace std;

int parent[1002];

int find(int a) {
    if (a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[a] = b;
    }
}

int arr[1002][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<pair<int, pair<int, int>>> graph;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i][0] >> arr[i][1];
        parent[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (find(a) != find(b)) {
            Union(a, b);
        }

    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            long long dx = arr[i][0] - arr[j][0];
            long long dy = arr[i][1] - arr[j][1];
            long long dis = dx * dx + dy * dy;
            double cost = sqrt(dis);
            graph.push_back({cost, {i, j}});
        }
    }
    sort(graph.begin(), graph.end());

    int len = graph.size();
    double ans = 0;

    for (int i = 0; i < len; ++i) {
        int a = graph[i].second.first;
        int b = graph[i].second.second;
        if (find(a) != find(b)) {
            Union(a, b);
            ans += graph[i].first;
        }
    }
    cout<<fixed;
    cout.precision(2);
    cout<<ans;
}