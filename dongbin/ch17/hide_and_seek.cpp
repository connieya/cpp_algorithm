#include "bits/stdc++.h"
#define INF 1e6
using namespace std;

int dis[20001];
vector<pair<int ,int>> graph[20001];

int main()
{
    int n,m ,a,b;
    cin >> n >> m;
    fill(dis, dis+n+1, INF);
    while (m--) {
        cin >> a>> b;
        graph[a].push_back({b,1});
        graph[b].push_back({a,1});
    }
    priority_queue<pair<int , int>> pq;
    pq.push({1,0});
    dis[1] = 0;
    while (!pq.empty()) {
        int now = pq.top().first;
        int cost = -pq.top().second;
        pq.pop();
        if (dis[now] < cost) continue;
        for (int i = 0; i < graph[now].size(); ++i) {
            int next_cost = cost + graph[now][i].second;
            int next_node = graph[now][i].first;
            if (dis[next_node] > next_cost) {
                dis[next_node] = next_cost;
                pq.push({next_node , -next_cost});
            }
        }
    }
    int maxNode = 0;
    int maxDistance = 0;
    vector<int> result;
    for (int i = 1; i <= n; ++i) {
        if(dis[i] > maxDistance){
             maxNode = i;
             maxDistance = dis[i];
             result.clear();
             result.push_back(i);
        }else if(dis[i] == maxDistance) {
            result.push_back(i);
        }
    }
    cout << maxNode << ' ' << maxDistance << ' ' << result.size();

}