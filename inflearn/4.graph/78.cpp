#include "bits/stdc++.h"

using namespace std;

struct Edge {
    int a;
    int b;
    int cost;

    Edge(int aa, int bb, int c) {
        a = aa;
        b = bb;
        cost = c;
    }

    bool operator<(Edge &b) {
        return cost < b.cost;
    }
};

int unf[100];
vector<Edge> edge;

int find(int a);

void Union(int a, int b);

int main(void) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        unf[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back(Edge(a, b, c));
    }
    sort(edge.begin(), edge.end());
    int ans = 0;
    for (int i = 0; i < edge.size(); ++i) {
        int a = edge[i].a;
        int b = edge[i].b;
        int cost = edge[i].cost;
        if (find(a) != find(b)) {
            ans += cost;
            Union(find(a), find(b));
        }
    }
    cout << ans;
}

int find(int a) {
    if (a == unf[a]) {
        return a;
    }
    return unf[a] = find(unf[a]);
}

void Union(int a, int b) {
    int fa = find(a);
    int fb = find(b);
    if (fa != fb) {
        unf[a] = b;
    }
}