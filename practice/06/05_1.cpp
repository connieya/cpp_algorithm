#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
int parent[1001];
vector<pair<ll, ll>> coordinate;
vector<pair<double, pair<int, int>>> road;

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


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        coordinate.push_back({x, y});
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        Union(a - 1, b - 1);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ll dx = coordinate[i].first - coordinate[j].first;
            ll dy = coordinate[i].second - coordinate[j].second;
            ll dis = dx * dx + dy * dy;
            double cost = sqrt(dis);
            road.push_back({cost, {i, j}});
        }
    }
    sort(road.begin(), road.end());
    int r = road.size();
    double sum = 0;
    int l = 0;
    for (int i = 0; i < r; ++i) {
        double d = road[i].first;
        int a = road[i].second.first;
        int b = road[i].second.second;
        if (find(a) != find(b)) {
            Union(a, b);
            sum += d;
            l++;
        }
        if (l == n - 1) break;
    }
    cout << fixed;
    cout.precision(2);
    cout << sum;
}