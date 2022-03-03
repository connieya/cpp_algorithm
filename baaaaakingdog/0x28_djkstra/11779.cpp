#include "bits/stdc++.h"

#define INF 21470000
using namespace std;

vector<pair<int, int>> graph[1001];
int pre[1001];
int d[1001];

void dijkstra(int start) {
    d[start] = 0;
    pre[start] = 0;
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
                pre[nxt_node] = now;
                d[nxt_node] = nxt_cost + cost;
                pq.push({-( nxt_cost + cost), nxt_node});
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
    cin >> start >> end;
    fill(d, d + n + 1, INF);
    dijkstra(start);
    stack<int> S;
    cout << d[end] << '\n';
    while (pre[end] != 0){
        S.push(end);
        end = pre[end];
    }
    S.push(end);
    cout << S.size() << '\n';
    while (!S.empty()) {
        cout << S.top() << ' ';
        S.pop();
    }

}