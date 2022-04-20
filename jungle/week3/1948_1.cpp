#include "bits/stdc++.h"

#define INF 10001

using namespace std;

vector<pair<int, int>> Road[INF];
vector<pair<int, int>> Road_r[INF];
int indegree[INF];
int road_time[INF];
bool visited[INF];

void topology(int n) {
    queue<int> Q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        int now_road = Q.front();
        Q.pop();
        for (auto next: Road[now_road]) {
            int time = next.second;
            int next_road = next.first;
            indegree[next_road]--;
            road_time[next_road] = max(road_time[next_road], time + road_time[now_road]);
            if (indegree[next_road] == 0) {
                Q.push(next_road);
            }
        }
    }
}

int topology_r(int end) {
    queue<int> Q;
    Q.push(end);
    int road_cnt = 0;
    while (!Q.empty()) {
        int now_road = Q.front();
        Q.pop();
        for (auto next: Road_r[now_road]) {
            int next_road = next.first;
            int time = next.second;
            if (road_time[now_road] - time == road_time[next_road]) {
                road_cnt++;
                if (!visited[next_road]) {
                    visited[next_road] = true;
                    Q.push(next_road);
                }

            }
        }
    }
    return road_cnt++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, start, end;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        Road[a].push_back({b, c});
        Road_r[b].push_back({a, c});
        indegree[b]++;
    }
    cin >> start >> end;
    topology(n);
    cout << road_time[end];
    cout << '\n';
    cout << topology_r(end);

}