#include "bits/stdc++.h"

#define INF 21470000

using namespace std;

vector<pair<int, int >> graph[801];

vector<int> dijkstra(int start) {
    vector<int> d(801);
    fill(d.begin(), d.end(), INF);
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (d[now] < cost) continue;
        for (auto nxt: graph[now]) {
            int nxt_node = nxt.first;
            int nxt_cost = nxt.second;
            if (d[nxt_node] > nxt_cost + cost) {
                d[nxt_node] = nxt_cost + cost;
                pq.push({-d[nxt_node], nxt_node});
            }
        }
    }
    return d;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, e, x, y;
    cin >> n >> e;
    for (int i = 0; i < e; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> x >> y;
    vector<int> dx = dijkstra(x);
    vector<int> dy = dijkstra(y);
    int ans = -1;
    if (dx[1] != INF && dx[y] != INF && dy[n] != INF){
        ans = dx[1]+dx[y] + dy[n];
    }
    if (dy[1] != INF &&  dy[x] != INF && dx[n] != INF) {
        ans = min(ans ,dy[1]+ dy[x] + dx[n]);
    }
    cout << ans;
}