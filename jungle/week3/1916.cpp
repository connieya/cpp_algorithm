#include "bits/stdc++.h"
#define INF 214700000
using namespace std;

vector<pair<int,int>> graph[1001];
priority_queue<pair<int,int>> pq;
int D[1001];

void dijkstra(int start) {
    pq.push({0,start});
    while (!pq.empty()){
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (D[now] < cost) continue;
        for(auto nxt : graph[now]){
            int next_node = nxt.first;
            int next_cost = nxt.second;
            if (D[next_node] > next_cost+cost){
                D[next_node] = next_cost+cost;
                pq.push({-(next_cost+cost), next_node});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m , start , end;
    cin >> n >> m;
    fill(D,D+n+1,INF);
    for (int i = 0; i < m; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to,cost});
    }
    cin >> start >> end;
    D[start] = 0;
    dijkstra(start);
    cout << D[end];
}