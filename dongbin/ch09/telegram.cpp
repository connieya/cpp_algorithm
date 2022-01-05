#include "bits/stdc++.h"
#define INF 1e9

using namespace std;

vector<pair<int, int>> graph[30001];
int city[30001];

void dijkstra(int start){
    priority_queue<pair<int ,int>> pq;
    pq.push({start,0});
    city[start] = 0;
    while (!pq.empty()) {
        int now = pq.top().first;
        int cost = -pq.top().second;
        pq.pop();
        if (city[now] < cost) continue;
        for (int i = 0; i < graph[now].size(); ++i) {
            int next = graph[now][i].first;
            int next_cost = cost + graph[now][i].second;
            if (next > next_cost){
                city[next] = next_cost;
                pq.push({next,-next_cost});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, c;
    int x, y, z;
    cin >> n >> m >> c;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> z;
        graph[x].push_back({y,z});
    }
    fill(city,city+n,INF);
    dijkstra(c);

    int count = 0;
    int maxDistance = 0;
    for (int i = 1; i < n; ++i) {
        if (i == c) continue;
        if (city[i] != INF){
            count++;
            maxDistance = max(maxDistance,city[i]);
        }
    }
    cout << count << ' ' << maxDistance;
}
