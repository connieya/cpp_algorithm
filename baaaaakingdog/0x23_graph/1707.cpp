#include "bits/stdc++.h"

using namespace std;

vector<int> graph[20001];
bool visited[20001];

void dfs(int v){
    visited[v] = true;
    for (int next: graph[v]) {
        if (!visited[next]){
            dfs(next);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, v, e;
    cin >> t;
    while (t--) {
        cin >> v >> e;
        graph->clear();
        fill(visited, visited+v+1,false);
        string answer = "NO";
        for (int i = 0; i < e; ++i) {
            int a ,b;
            cin >> a >> b;
            graph[a].push_back(b);
        }
        int ans = 0;
        for (int i = 1; i <= v; ++i) {
            if (!visited[i]){
                dfs(i);
                ans++;
            }
            if (ans == 2) {
                answer = "YES";
                break;
            }
        }
        cout << answer << '\n';
    }
}