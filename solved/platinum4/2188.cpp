#include "bits/stdc++.h"
#define INF 201

using namespace std;

vector<int> graph[INF];

// 각 정점이 매칭된 반대편 정점 번호
int a[INF];
int b[INF];
bool visited[INF];

bool dfs(int start){
    visited[start] = true;
    for (int next : graph[start]) {
        if (b[next] == -1 || !visited[b[next]] && dfs(b[next])){
            a[start] = next;
            b[next] = start;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,s,c,ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        for (int j = 0; j < s; ++j) {
            cin >> c;
            graph[i].push_back(c);
        }
    }
    fill(a,a+n+1,-1);
    fill(b,b+m+1,-1);
    for (int i = 1; i <=n; ++i) {
        if (a[i] == -1){
            fill(visited,visited+n+1,false);
            if (dfs(i)) ans++;
        }
    }
    cout << ans;

}