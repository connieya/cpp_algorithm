#include "bits/stdc++.h"

using namespace std;

vector<int> graph[3002];
int checked[3002][3002];

void dfs(int start , int num , int L , int E) {
    if (L == E){
        cout << "YES";
        exit(0);
    }
    for (int nxt :graph[start]) {
        if (checked[start][nxt] == num || checked[nxt][start] == num) continue;
        checked[start][nxt] = checked[nxt][start] = num;
        dfs(nxt,num,L+1,E);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int V,E;
    cin >> V >> E;
    for (int i = 0; i < E; ++i) {
        int a ,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <=V; ++i) {
        dfs(i,i,0,E);
    }
    cout << "NO";
}