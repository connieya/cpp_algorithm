#include "bits/stdc++.h"

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    bool visited[n + 1];
    vector<pair<int, int> > graph[30];
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    int ans = 0;
    while (!pq.empty()) {
        int node = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (!visited[node]) {
            ans += cost;
            visited[node] = true;
            for (int i = 0; i < graph[node].size(); ++i) {
                int next = graph[node][i].first;
                pq.push({-graph[node][i].second, next});
            }
        }
    }
    cout << ans;
}