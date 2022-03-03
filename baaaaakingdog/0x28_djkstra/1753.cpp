#include "bits/stdc++.h"
#define INF 2147000

using namespace std;

vector<pair<int ,int>> graph[20001];
int d[20001];

void dijkstra(int start) {
    d[start] = 0;
    priority_queue<pair<int ,int>> pq;
    pq.push({0,start});
    while (!pq.empty()) {
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (d[now] < cost) continue;
        for (auto nxt : graph[now]) {
            int nxt_node = nxt.first;
            int nxt_cost = nxt.second;
            if (d[nxt_node] > cost + nxt_cost) {
                d[nxt_node] = cost + nxt_cost;
                pq.push({-(cost+nxt_cost),nxt_node});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, start;
    cin >> n >> m >> start;
    for (int i = 0; i < m; ++i) {
        int a ,b ,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    fill(d,d+n+1,INF);
    dijkstra(start);
    for (int i = 1; i <= n; ++i) {
        if (d[i] == INF) {
            cout << "INF" << '\n';
            continue;
        }
        cout << d[i] << '\n';
    }
}