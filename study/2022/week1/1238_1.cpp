#include "bits/stdc++.h"
#define INF 1e7
using namespace std;

int d1[1001];
int d2[1001];
vector<pair<int,int>> graph1[1001];
vector<pair<int,int>> graph2[1001];
void dijkstra1(int start);
void dijkstra2(int start);
int n,m,x;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x;
    int a,b,cost;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> cost;
        graph1[a].push_back({b, cost});
        graph2[b].push_back({a, cost});
    }
    dijkstra1(x);
    dijkstra2(x);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans , d1[i]+d2[i]);
    }
    cout << ans;
}
void dijkstra1(int start) {
    priority_queue<pair<int , int>> pq;
    fill(d1,d1+1001,INF);
    d1[start] = 0;
    pq.push({start,0});
    while (!pq.empty()){
        int now = pq.top().first;
        int cost = -pq.top().second;
        pq.pop();
        if (d1[now] < cost) continue;
        for (auto p : graph1[now]) {
            int next = p.first;
            int next_cost = p.second;
            if (d1[next] > d1[now] + next_cost){
                d1[next] = d1[now] + next_cost;
                pq.push({next,-(d1[now]+next_cost)});
            }
        }
    }
}
void dijkstra2(int start) {
    priority_queue<pair<int , int>> pq;
    fill(d2,d2+1001,INF);
    d2[start] = 0;
    pq.push({start,0});
    while (!pq.empty()){
        int now = pq.top().first;
        int cost = -pq.top().second;
        pq.pop();
        if (d2[now] < cost) continue;
        for (auto p : graph2[now]) {
            int next = p.first;
            int next_cost = p.second;
            if (d2[next] > d2[now] + next_cost){
                d2[next] = d2[now] + next_cost;
                pq.push({next,-(d2[now]+next_cost)});
            }
        }
    }
}