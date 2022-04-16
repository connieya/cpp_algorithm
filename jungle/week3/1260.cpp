#include "bits/stdc++.h"

using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int start) {
    visited[start] = true;
    cout << start << ' ';
    for (int nxt: graph[start]) {
        if (!visited[nxt]) {
            dfs(nxt);

        }
    }
}

void init(int n) {
    for (int i = 0; i <= n; ++i) {
        visited[i] = false;
    }
}

void bfs(int start) {
    queue<int> Q;
    cout << start << ' ';
    Q.push(start);
    visited[start] = true;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int nxt: graph[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                cout << nxt << ' ';
                Q.push(nxt);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, v;
    cin >> n >> m >> v;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(v);
    cout << '\n';
    init(n);
    bfs(v);

}