#include "bits/stdc++.h"
#define MAX 100001
using namespace std;

vector<int> graph[MAX+1001];
int dis[MAX+1001];
int n,k,m;

void bfs(){
    queue<int> q;
    q.push(1);
    dis[1] = 1;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        for(auto nxt : graph[now]) {
           if(dis[nxt] == -1){
               if(nxt > n){
                   dis[nxt] = dis[now];
               }else {
                   dis[nxt] = dis[now]+1;
                   if(nxt == n){
                       cout << dis[nxt];
                       exit(0);
                   }
               }
               q.push(nxt);
           }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> m;
    int node;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> node;
            graph[i+n].push_back(node);
            graph[node].push_back(i+n);
        }
    }
    memset(dis,-1,sizeof dis);
    bfs();
    cout << dis[n];
}