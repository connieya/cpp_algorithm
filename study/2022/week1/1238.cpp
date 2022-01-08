#include "bits/stdc++.h"
#define INF 1e7
using namespace std;

void dijkstra(int start);
int d[1001];
int ans[1001];
vector<pair<int ,int >>  graph[1001];
int n,m,x;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x;
    int a,b,cost , res =0;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> cost;
        graph[a].push_back({b,cost});
    }

    for (int i = 1; i <=n; ++i) {
        if (i == x) continue;
        fill(d,d+1001,INF);
        d[i] = 0;
        dijkstra(i);
        ans[i] = d[x];
    }
    fill(d,d+1001,INF);
    d[x] = 0;
    dijkstra(x);
    for (int i = 1; i <= n; ++i) {
        res = max(res , ans[i]+d[i]);
    }
    cout << res << ' ';
}

void dijkstra(int start) {
    priority_queue<pair<int ,int>> pq;
    pq.push({start , 0});
    while (!pq.empty()){
        int now = pq.top().first;
        int cost =-pq.top().second;
        pq.pop();
        if (d[now] < cost) continue;
        for(auto next : graph[now]) {
            int next_town = next.first;
            int next_cost = next.second;
            if (d[next_town] > next_cost+d[now]) {
                d[next_town] = next_cost + d[now];
                pq.push({next_town , -(next_cost+d[now])});
            }
        }
    }
}