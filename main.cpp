#include "bits/stdc++.h"

using namespace std;

vector<int> graph[100];

int dfs(int start){
    int cnt = 0;
    for(int next : graph[start]){
        cnt++;
        dfs(next);
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    cout << dfs(4);
}