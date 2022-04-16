#include "bits/stdc++.h"

using namespace std;

vector<int> graph[100001];
bool visited[100001];
int parents[100001];

void dfs(int start){
    visited[start] = true;
    for (int nxt : graph[start]) {
        if (!visited[nxt]){
            parents[nxt] = start;
            dfs(nxt);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    for (int i = 2; i <= n; ++i) {
        cout << parents[i] << '\n';
    }



}