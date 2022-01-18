#include "bits/stdc++.h"

using namespace std;

int d[10000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    cout << n << m;
    vector<pair<int, int>> bridge[10001];
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        bridge[a].emplace_back(b, c);
    }
    cin >> x >> y;
    fill(d,d+10000,-1);
    priority_queue<pair<int ,int>> pq;
    pq.push({0,x});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int now = cur.second;
        int weight =cur.first;
        if (d[now] > weight ) continue;
        for (auto next : bridge[now]) {
            int next_bridge = next.first;
            int next_weight = next.second;
            if (d[next_bridge] < next_weight+weight) {
                d[next_bridge] = next_weight + weight;
                pq.push({next_weight+weight , next_bridge});
            }
        }
    }
    cout << d[y];
}