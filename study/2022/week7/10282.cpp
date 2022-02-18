#include "bits/stdc++.h"
#define INF 2117000000
using namespace std;

int d[10001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int  count, dependency , start , ans = 0;
        cin >> count >> dependency >> start;
        vector<pair<int ,int>> graph[10001];
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < dependency; ++i) {
            int a , b , time;
            cin >> a >> b >>time;
            graph[b].push_back({a,time});
        }
        fill(d,d+10001,INF);
        d[start] = 0;
        pq.push({0,start});
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int now = cur.second;
            int cost = -cur.first;
            if (d[now] < cost) continue;
            for (auto next : graph[now]) {
                int next_node = next.first;
                int next_cost = next.second;
                if (d[next_node] > next_cost+cost){
                    d[next_node] = next_cost+cost;
                    pq.push({-(next_cost+cost), next_node});
                }
            }
        }
        int cnt = 0;
        for (int i=1; i<=count; i++){
            if (d[i] == INF) continue;
            cnt++;
            if (d[i] > ans) {
                ans = d[i];
            }
        }
        cout << cnt << ' ' << ans <<'\n';

    }
}