#include "bits/stdc++.h"

#define INF 2137000000
using namespace std;

long long d[100001];
vector<pair<int, int>> graph[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[b].push_back({a, c});
    }
    fill(d, d + n + 1, INF);
    priority_queue<pair<long long , int>> pq;
    for (int i = 0; i < k; ++i) {
        int start;
        cin >> start;
        pq.push({0, start});
    }
    while (!pq.empty()) {
        int now = pq.top().second;
        long long cost = -pq.top().first;
        pq.pop();
        if (d[now] < cost) continue;
        for (auto nxt: graph[now]) {
            if (d[nxt.first] > cost + nxt.second) {
                d[nxt.first] = cost + nxt.second;
                pq.push({-d[nxt.first], nxt.first});
            }
        }
    }
    long long node, distance = -1;
    for (int i = 1; i <= n; ++i) {
        if (distance < d[i]) {
            distance = d[i];
            node = i;
        }
    }
    cout << node << '\n' << distance;
}