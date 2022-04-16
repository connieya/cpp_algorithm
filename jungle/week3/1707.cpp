#include "bits/stdc++.h"

using namespace std;

bool visited[20001];
int B[20001];
vector<int> graph[20001];

void dfs(int start, int color) {
    visited[start] = true;
    B[start] = color;
    for (int nxt: graph[start]) {
        if (!visited[nxt]) {
            dfs(nxt, color * -1);
        }

    }
}

bool isBipartiteGraph(int v) {
    for (int i = 1; i <= v; ++i) {
        for (int nxt: graph[i]) {
            if (B[i] == 0 || B[nxt] == 0) continue;
            if (B[i] == B[nxt]) return false;
        }
    }

    return true;

}

void init(int v) {
    for (int i = 1; i <= v; ++i) {
        graph[i].clear();
        visited[i] = false;
        B[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int v, e;
        cin >> v >> e;
        for (int i = 0; i < e; ++i) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for (int i = 1; i <=v ; ++i) {
            if (!visited[i]){
                dfs(i, 1);
            }
        }

        if (isBipartiteGraph(v)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
        init(v);
    }
}