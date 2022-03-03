#include "bits/stdc++.h"

#define INF 214700000

using namespace std;

int dis[2001];
vector<pair<int, int>> graph[2001];
vector<int> destination;

void init() {
    for (int i = 0; i <= 2000; ++i) {
        graph[i].clear();
    }
}

void input(int road) {
    for (int i = 0; i < road; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
}

vector<int> dijkstra(int start) {
    vector<int> d(20001);
    fill(d.begin(), d.end(), INF);
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        for (auto nxt: graph[now]) {
            int nxt_node = nxt.first;
            int nxt_cost = nxt.second;
            if (d[nxt_node] > nxt_cost + cost) {
                d[nxt_node] = nxt_cost + cost;
                pq.push({-d[nxt_node], nxt_node});
            }
        }
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int node, road, c, start, a, b;
        cin >> node >> road >> c;
        cin >> start >> a >> b;
        init();
        input(road);
        destination.clear();
        for (int i = 0; i < c; ++i) {
            int d;
            cin >> d;
            destination.push_back(d);
        }
        vector<int> V = dijkstra(start);
        vector<int> a_dis = dijkstra(a);
        vector<int> b_dis = dijkstra(b);
        vector<int> ans;
        for (int d : destination) {
            if (V[d] == a_dis[start]+a_dis[b]+b_dis[d]) {
                ans.push_back(d);
            }
            if (V[d] == b_dis[start]+b_dis[a]+a_dis[d]){
                ans.push_back(d);
            }
        }
        sort(ans.begin(),ans.end());
        for (int a : ans) {
            cout << a << ' ';
        }
        cout << '\n';
    }
}