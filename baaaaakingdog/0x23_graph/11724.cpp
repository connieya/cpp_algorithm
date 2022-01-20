#include "bits/stdc++.h"

using namespace std;

vector<int> graph[1001];
bool visited[1001];

void bfs(int v) {
    stack<int> S;
    S.push(v);
    while (!S.empty()){
        int v = S.top();
        S.pop();
        for (int next: graph[v]) {
            if (!visited[next]) {
                visited[next] = true;
                S.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            ans++;
            visited[i] = true;
            bfs(i);
        }
    }
    cout << ans;
}