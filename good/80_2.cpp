#include "bits/stdc++.h"

using namespace std;

struct Edge {
    int vex;
    int dis;

    Edge(int a, int b) {
        vex = a;
        dis = b;
    }

    bool operator<(const Edge &b) const {
        return dis > b.dis;
    }
};

int main(void) {
    priority_queue<Edge> Q;
    int  n, m, a, b, c;
    cin >> n >> m;
    int distance[30];
    fill(distance,distance+30,214700);
    vector<pair<int, int> > graph[30];
    for (int j = 0; j < m; ++j) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    Q.push(Edge(1, 0));
    distance[1] = 0;
    while (!Q.empty()) {
        int now = Q.top().vex;
        int now_cost = Q.top().dis;
        Q.pop();
        if (distance[now] < now_cost) continue;
        for (int j = 0; j < graph[now].size(); ++j) {
            int next = graph[now][j].first;
            int nextDis = now_cost + graph[now][j].second;
            if (distance[next] > nextDis) {
                distance[next] = nextDis;
                Q.push(Edge(next, nextDis));
            }
        }
    }
    for (int j = 2; j <= n; ++j) {
        if (distance[j] == 214700) {
            cout << j << " : " << "impossible" << '\n';
        } else {
            cout << j << " : " << distance[j] << '\n';
        }
    }
}