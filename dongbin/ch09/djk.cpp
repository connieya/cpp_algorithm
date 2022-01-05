#include "bits/stdc++.h"

#define INF 1e9

using namespace std;

int n, m, start;
// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
vector<pair<int, int>> graph[100001];
// 최단거리 테이블 만들기
int dir[100001];

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    // 시작 노드로 가기 위한 최단 경로는 0으로 설정함
    pq.push({0, start});
    // 시작 노드에 대해 초기화
    dir[start] = 0;
    while (!pq.empty()) {
        // 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
        int dist = -pq.top().first; // 현재 노드 까지의 비용
        int now = pq.top().second; // 현재 노드
        pq.pop();
        // 현재 노드가 이미 처리 된적이 있으면 무시
        if (dir[now] < dist) continue;
        // 현재 노드와 연결된 다른 인접한 노드들을 확인
        for (int i = 0; i < graph[now].size(); ++i) {
            int cost = dist + graph[now][i].second;
            if (dir[graph[now][i].first] > cost) {
                dir[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }

}

int main(void) {
    cin >> n >> m >> start;
    // 모든 간선 정보를 입력 받기
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        // a번 노드에서 b번 노드로 가는 비용이 c
        graph[a].push_back({b, c});
    }
    // 최단거리 테이블을 모두 무한으로 초기화
    fill_n(dir, 100001, INF);
    // 다익스트라 알고리즘을 수행
    dijkstra(start);
    // 모든 노드로 가기 위한 최단 거리를 출력
    for (int i = 1; i <= n; ++i) {
        if (dir[i] == INF) {
            cout << "INFINITY" << '\n';
        } else {
            cout << dir[i] << '\n';
        }
    }
}