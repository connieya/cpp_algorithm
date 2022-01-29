#include "bits/stdc++.h"

using namespace std;

vector<pair<int,int>> graph[10001];
bool visited[10001];
int x,y;

bool bfs(int cost) {
    visited[x] = true;
    queue<int> Q;
    Q.push(x);
    while (!Q.empty()){
        int now = Q.front();
        Q.pop();
        if(now == y) return true;
        for (auto nxt : graph[now]) {
            int next = nxt.first;
            int next_cost = nxt.second;
            if(!visited[next] && cost <= next_cost) {
                visited[next] = true;
                Q.push({next});
            }

        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, start = 0, end = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, cost;
        cin >> a >> b >> cost;
        graph[a].push_back({b, cost});
        graph[b].push_back({a, cost});
        end = max(end, cost);
     }
    cin >> x >> y;
    while (start <= end) {
        int mid = (start + end) /2;
        fill(visited,visited+10001,false);
        if(bfs(mid)){
            start = mid+1;
        }else {
            end = mid-1;
        }
    }
    cout << end;

}