#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> p;

int n, m, k;
vector<p> graph[1001];
priority_queue<int> heap[1010]; // 최대 힙

void kth_dijkstra() {
    priority_queue<p, vector<p>, greater<p>> pq; // 최소힙
    heap[1].push(0);
    pq.push({0, 1});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int now = cur.second;
        int cost = cur.first;
        for (auto nxt: graph[now]) {
            int next_node = nxt.first;
            int next_cost = nxt.second;
            if (heap[next_node].size() < k) {
                heap[next_node].push(next_cost + cost);
                pq.push({next_cost+cost,next_node});
            } else if (heap[next_node].top() > next_cost + cost) {
                heap[next_node].pop();
                heap[next_node].push(next_cost + cost);
                pq.push({next_cost + cost, next_node});
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    kth_dijkstra();
    for (int i = 1; i <= n; ++i) {
        if (heap[i].size() != k) {
            cout << -1 << '\n';
        } else {
            cout << heap[i].top() << '\n';
        }
    }

}