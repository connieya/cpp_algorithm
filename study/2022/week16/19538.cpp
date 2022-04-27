#include "bits/stdc++.h"

#define INF 200001
using namespace std;

int ans[INF];
int cnt[INF];
vector<int> graph[INF];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, p, m, x;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        while (1) {
            cin >> p;
            if (!p) break;
            graph[i].push_back(p);
        }
    }
    cin >> m;
    queue<int> Q ,t_Q;
    fill(ans,ans+n+1,-1);
    for (int i = 0; i < m; ++i) {
        cin >> x;
        Q.push(x);
        ans[x] = 0;
        for (int next: graph[x]) {
            cnt[next]++;
        }
    }
    int L = 1;
    while (!Q.empty()){
        int len = Q.size();
        vector<int> tmp;
        for (int i = 0; i < len; ++i) {
            int rumor = Q.front();
            Q.pop();
            for (int next : graph[rumor]) {
                int size = graph[next].size()+1;
                if(size/2 <= cnt[next] && ans[next] == -1){
                    Q.push(next);
                    tmp.push_back(next);
                    ans[next] = L;
                }
            }
        }
        for (int t: tmp) {
            for (int r : graph[t]) {
                cnt[r]++;
            }
        }
        L++;
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
}