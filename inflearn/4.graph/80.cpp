#include "bits/stdc++.h"
#define INF 1e9

using namespace std;
vector<pair<int ,int>> graph[1001];
int dir[1001];

void dijkstra(int start){
    priority_queue<pair<int , int>> pq;
      pq.push({start,0});
    while (!pq.empty()) {
        int now = pq.top().first; // 현재 노드
        int dist = -pq.top().second; // 비용
        pq.pop();
        if (dir[now] < dist ) continue; // 처음 시작 노드에 있는 간선들 중에서 최소 값 (1번 만에 갈 수 있는 간선)이기 때문에
        // 2번 , 3번만에 가는 노드보다 볼것도 없이 최소 값이다. .
        for (int i = 0; i < graph[now].size(); ++i) {
            int cost = dist + graph[now][i].second; // pq 의  first , second 랑 헷갈리면 안됨
            // 간단하게 생각하면 현재 노드의 비용이랑 그 다음 이동할 노드의 비용의 합을 가리킴
            if (dir[graph[now][i].first] > cost) {
                // 다음 노드의 비용이 현재 노드의 비용과 다음 노드의 비용의 합보다 크다면 ~
                dir[graph[now][i].first] = cost;
                pq.push({graph[now][i].first,-cost});
            }
        }
    }
}

int main()
{
    int n ,m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b ,c;
        cin >> a >> b >>c;
        graph[a].push_back({b,c}); // 위에 priority queue 의 first , second 랑 헷갈리면 안됨
    }
    fill(dir,dir+n+1,INF);
    dijkstra(1);
    for (int i = 2; i <= n; ++i) {
        if (dir[i] == INF){
            cout << i << " : " << "impossible" << '\n';
        }else {
            cout << i << " : " << dir[i] << '\n';
        }
    }

}