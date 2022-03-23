#include "bits/stdc++.h"
#define WHITE 1
#define BLACK 2
#define MAX 20001

using namespace std;

vector<int> graph[MAX];
int visited[MAX];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        graph[i].clear();
        visited[i] = 0;
    }
}

void dfs(int now ) {
    if (visited[now] == 0){
        visited[now] = WHITE;
    }
    for (int nxt : graph[now]) {
        if (visited[nxt] == 0){
            if (visited[now] == WHITE){
                visited[nxt] = BLACK;
            } else if (visited[now] == BLACK) {
                visited[nxt] = WHITE;
            }
            dfs(nxt);
        }
    }
}

bool isBipartiteGraph(int v){
    for (int i = 1; i <= v; ++i) {
        for (int nxt : graph[i]) {
            if (visited[i] == visited[nxt]) return false;
        }
    }
    return true;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, v, e;
    cin >> t;
    while (t--) {
        cin >> v >> e;
        for (int i = 0; i < e; ++i) {
            int a ,b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for (int i = 1; i <= v; ++i) {
            if (visited[i] == 0) {
                dfs(i);
            }
        }
        if (isBipartiteGraph(v)){
            cout << "YES" << '\n';
        }else {
            cout << "NO" << '\n';
        }
        init(v);
    }
}