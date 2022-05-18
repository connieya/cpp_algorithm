#include "bits/stdc++.h"

#define INF 3001

using namespace std;

int n;
int checked[INF];
int dist[INF];
int indegree[INF];
vector<int> graph[INF];

void bfs() {
    queue<int> Q;
    for (int i = 1; i <= n; ++i) {
        if(indegree[i] == 1) Q.push(i);
    }

    while (!Q.empty()){
        int cur = Q.front();
        Q.pop();
        indegree[cur]--;
        for(int next : graph[cur]){
            if(!indegree[next]) continue;
            if(--indegree[next] == 1) Q.push(next);
        }
    }

}

void solve() {
    queue<int> Q;
    fill(dist,dist+n+1,-1);
    for (int i = 1; i <= n; ++i) {
        if(!indegree[i]) continue;
        dist[i] = 0;
        Q.push(i);
        while (!Q.empty()){
            int now = Q.front();
            Q.pop();
            for (int next : graph[now]) {
                if(!indegree[next] && dist[next] == -1){
                    dist[next] = dist[now]+1;
                    Q.push(next);
                }
            }
        }
    }
}

void print(){
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        indegree[a]++;
        indegree[b]++;
    }
    bfs();
    solve();
    print();
}