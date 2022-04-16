#include "bits/stdc++.h"

using namespace std;

vector<int> graph[1001];
bool visited[1001];


void dfs(int start) {
    visited[start] = true;
    for (int nxt: graph[start]) {
        if (!visited[nxt]) {
            dfs(nxt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
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
            dfs(i);
            ans++;
        }
    }
    cout << ans;
}