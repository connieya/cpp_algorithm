#include "bits/stdc++.h"
#define MX 1010
using namespace std;

long long buildings[MX];
long long ans[MX];
int inDegree[MX];
vector<int> graph[MX];
int t,n,m,w;

void init () {
    for (int i = 0; i < MX; ++i) {
        graph[i].clear();
    }
    fill(inDegree, inDegree+MX,0);
    fill(ans,ans+MX,0);
}

void topology() {
    queue<int> Q;
    for (int i = 1; i <=n ; ++i) {
        if (inDegree[i] == 0){
            ans[i] = buildings[i];
            Q.push(i);
        }
    }
    while (!Q.empty()){
        int now = Q.front();
        Q.pop();
        for (int nxt: graph[now]) {
            inDegree[nxt]--;
            ans[nxt] = max(ans[now]+buildings[nxt],ans[nxt]);
            if (inDegree[nxt] == 0){
                Q.push(nxt);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        init();
        for (int i = 1; i <= n; ++i) {
            cin >> buildings[i];
        }
        for (int i = 0; i < m; ++i) {
            int a,b;
            cin >> a >> b;
            graph[a].push_back(b);
            inDegree[b]++;
        }
        cin >>w;
        topology();
        cout << ans[w] << '\n';
    }
}
