#include "bits/stdc++.h"

using namespace std;

int n,m,k,x;

vector<int> graph[300001];
vector<int> d(300001,-1);

int main(void)
{
    cin >> n >> m >> k >> x;
    int a,b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a].push_back(b);
    }
    d[x] = 0;
    queue<int> Q;
    Q.push(x);
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        for (int i = 0; i < graph[now].size(); ++i) {
            int next = graph[now][i];
            if(d[next] == -1) {
                d[next] = d[now]+1;
                Q.push(next);
            }
        }
    }
    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        if (d[i] == k) {
            cout << i << '\n';
            flag = true;
        }
    }
    if(!flag) {
        cout << -1 << '\n';
    }
}