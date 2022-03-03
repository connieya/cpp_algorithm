#include "bits/stdc++.h"

#define INF 214700000

using namespace std;

vector<pair<int, int>> graph[1001];
long long d[1001];

void dijkstra(int start) {
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (d[now] < cost) continue;
        for (auto nxt: graph[now]) {
            int nxt_node = nxt.first;
            int nxt_cost = nxt.second;
            if (d[nxt_node] > nxt_cost + cost) {
                d[nxt_node] = nxt_cost + cost;
                pq.push({-(nxt_cost + cost), nxt_node});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, start, end;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    fill(d, d + n + 1, INF);
    cin >> start >> end;
    dijkstra(start);
    cout << d[end];
}