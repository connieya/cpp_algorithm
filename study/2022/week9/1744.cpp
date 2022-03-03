#include "bits/stdc++.h"

using namespace std;

int arr[1001][2];
vector<pair<double, pair<int, int>>> graph;
int parent[1001];

int find(int a);

void Union(int a, int b);

int find(int a) {
    if (a == parent[a]) {
        return a;
    }
    return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    if (aa != bb) {
        parent[aa] = bb;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        cin >> arr[i][0] >> arr[i][1];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            long long x = arr[i][0] - arr[j][0];
            long long y = arr[i][1] - arr[j][1];
            long long dis = x * x + y * y;
            double cost = sqrt(dis);
            graph.push_back({cost, {i, j}});
        }
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (find(a) != find(b)) {
            Union(a, b);
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
    cout << fixed;
    cout.precision(2);
    cout << ans;
}