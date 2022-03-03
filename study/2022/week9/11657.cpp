#include "bits/stdc++.h"

#define INF 214700000

using namespace std;

vector<pair<pair<int,int>,int>> graph;

long long d[501];
int n, m;

bool isNegativeCycle() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int now = graph[j].first.first;
            int nxt = graph[j].first.second;
            int cost = graph[j].second;
            if (d[now] != INF && d[nxt] > d[now]+cost){
                if (i==n-1) return true;
                d[nxt] = d[now]+cost;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({{a,b},c});
    }
    fill(d, d + n + 1, INF);
    d[1] = 0;
    if (isNegativeCycle()) {
        cout << -1;
        return 0;
    }
    for (int i = 2; i <= n; ++i) {
        if (d[i] == INF) {
            cout << -1 << '\n';
            continue;
        }
        cout << d[i] << '\n';
    }
}