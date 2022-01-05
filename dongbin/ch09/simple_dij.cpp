#include "bits/stdc++.h"
#define INF 1e9

using namespace std;

int n,m,start;
// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
vector<pair<int,int>> graph[100001];
// 방문한 적이 있는지 체크하는 목적의 배열 만들기
bool visited[100001];
// 최단거리 테이블 만들기
int dir[100001];

// 방문하지 않은 노드 중에서, 가장 최단거리가 짧은 노드의 번호를 반환
int getSmallestNode() {
    int min_value = INF;
    int index = 0;
    for (int i = 1; i <= n; ++i) {
        if (dir[i] < min_value && !visited[i]) {
            min_value = dir[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int start) {
    // 시작 노드에 대해 초기화
    dir[start] = 0;
    visited[start] = true;
    for (int i = 0; i < graph[start].size(); ++i) {
        dir[graph[start][i].first] = graph[start][i].second;
    }
    for (int i = 1; i < n; ++i) {
        // 현재 최단 거리가 가장 짧은 노드를 꺼내서, 방문 처리
        int now = getSmallestNode();
        visited[now] = true;
        for (int j = 0; j < graph[now].size(); ++j) {
            int cost = dir[now] + graph[now][j].second;
            if (cost < dir[graph[now][j].first]){
                dir[graph[now][j].first] =cost;
            }
        }
    }
}

int main(void)
{
    cin >> n >> m >> start;
    // 모든 간선 정보를 입력 받기
    for (int i = 0; i < m; ++i) {
        int a,b,c;
        cin >> a >> b >> c;
        // a번 노드에서 b번 노드로 가는 비용이 c
        graph[a].push_back({b,c});
    }
    // 최단거리 테이블을 모두 무한으로 초기화
    fill_n(dir,100001,INF);
    dijkstra(start);
    // 모든 노드로 가기 위한 최단 거리를 출력
    for (int i = 1; i <= n; ++i) {
        if (dir[i] == INF){
            cout << "INFINITY" << '\n';
        }else {
            cout << dir[i] << '\n';
        }
    }
}