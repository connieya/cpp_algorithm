#include "bits/stdc++.h"

using namespace std;

int parent[100001];

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
    parent[aa] = bb;
}

vector<pair<int, int>> x;
vector<pair<int, int>> y;
vector<pair<int, int>> z;
vector<pair<int, pair<int, int>>> edges;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        x.push_back({a, i}); // i번 행성의 x 좌표는 a이다.
        y.push_back({b, i}); // i번 행성의 y 좌표는 b이다.
        z.push_back({c, i}); // i번 행성의 z 좌표는 c이다.
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());
    for (int i = 0; i < n - 1; ++i) {
        int x_cost = x[i + 1].first - x[i].first;
        int y_cost = y[i + 1].first - y[i].first;
        int z_cost = z[i + 1].first - z[i].first;
        edges.push_back({x_cost, {x[i].second, x[i + 1].second}});
        edges.push_back({y_cost, {y[i].second, y[i + 1].second}});
        edges.push_back({z_cost, {z[i].second, z[i + 1].second}});
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (int i = 0; i < edges.size(); ++i) {
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if (find(a) != find(b)) {
            ans += edges[i].first;
            Union(a, b);
        }
    }
    cout << ans;
}
