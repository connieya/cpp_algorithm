#include "bits/stdc++.h"
#define INF 21470000
using namespace std;

int dp[10001];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,start;
    cin >> n >> m >> start;
    vector<pair<int,int>> graph[10001];
    for (int i = 0; i < m; ++i) {
        int a , b , time;
        cin >> a >> b >> time;
        graph[b].push_back({a,time});
    }
    fill(dp,dp+10001,INF);
    dp[start] = 0;
    priority_queue<pair<int ,int>> pq;
    pq.push({0,start});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int now = cur.second;
        int cost = -cur.first;
        for (auto nxt : graph[now]) {
            int next = nxt.first;
            int next_cost = nxt.second;
            if (dp[next] > next_cost+cost){
                dp[next] = next_cost+cost;
                pq.push({-(next_cost+cost) , next});
            }
        }
    }
    for (int i=1; i<=n; i++){
        cout << dp[i] << ' ' ;
    }

}