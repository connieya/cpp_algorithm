#include "bits/stdc++.h"

using namespace std;

vector<int> graph[2001];
bool visited[2001];

void dfs(int L , int idx) {
    visited[L] = true;
    if (idx == 4){
        cout << 1;
        exit(0);
    }

    for(int next : graph[L]){
        if(!visited[next]){
            dfs(next, idx+1);
        }

    }
    visited[L] = false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        dfs(i,0);
    }
    cout << 0;
}