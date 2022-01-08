#include "bits/stdc++.h"

#define INF 1e6
using namespace std;

int d[101];
vector<pair<int, int>> edges[101];

int main(void) {
    int n, m;
    cin >> n >> m;
    fill(d, d + 101, INF);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
    }
    int start, end;
    cin >> start >> end;
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (d[now] < cost) continue;
        for (auto p : edges[now]) {
            int next = p.first;
            int next_cost = p.second;
            if (d[next] > d[now] + next_cost) {
                d[next] = d[now] + next_cost;
                pq.push({-(d[now]+next_cost) , next});
            }
        }
    }

}