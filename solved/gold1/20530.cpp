#include "bits/stdc++.h"

#define INF 200001

using namespace std;

int n, m;
vector<int> graph[INF];
int parent[INF];
int indegree[INF];

int find(int a) {
    if (a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[a] = b;
    }
}

void dfs(int start, int prev) {
    for (int next: graph[start]) {
        if (indegree[next] || next == prev) continue;
        dfs(next, start);
        Union(next, start);
    }

}

void bfs() {
    queue<int> Q;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        if (indegree[i] == 1) {
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        indegree[now]--;
        for (int next: graph[now]) {
            if (!indegree[next]) continue;
            if (--indegree[next] == 1) {
                Q.push(next);
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        if (indegree[i]) dfs(i, -1);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        indegree[a]++;
        indegree[b]++;
    }
    bfs();
    solve();
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        find(a) == find(b) ? cout << "1\n" : cout << "2\n";
    }
}