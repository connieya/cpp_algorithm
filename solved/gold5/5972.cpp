#include "bits/stdc++.h"
#define INF 21470000
using namespace std;

vector<pair<int, int >> graph[50001];
int D[50001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    for (int i = 2; i <= n; ++i) {
        D[i] = INF;
    }
    priority_queue<pair<int,int >> PQ;
    PQ.push({0,1});
    while (!PQ.empty()) {
        auto cur = PQ.top();
        PQ.pop();
        int now = cur.second;
        int cost = -cur.first;
        if (D[now] > cost) continue;
        for (auto nxt : graph[now]) {
            int nxt_node = nxt.first;
            int nxt_cost = nxt.second;
            if (D[nxt_node] > nxt_cost+cost) {
                D[nxt_node] = nxt_cost+cost;
                PQ.push({-(nxt_cost+cost),nxt_node});
            }
        }
    }
    cout << D[n];

}