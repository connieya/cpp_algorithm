#include "bits/stdc++.h"
#define INF 2147000000
using namespace std;

int d[21];

struct Edge{
    int s;
    int e;
    int val;
    Edge(int  a,int b,int c) {
        s=a;
        e=b;
        val =c;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<Edge> ed;
    int n,m ,s,e;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a,b,c;
        cin >> a >> b >> c;
        ed.push_back(Edge(a,b,c));
    }
    for (int i = 1; i <= n; ++i) {
        d[i] = INF;
    }
    cin >> s >> e;
    d[s] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < ed.size(); ++j) {
            int u = ed[j].s;
            int v = ed[j].e;
            int w = ed[j].val;
            if (d[u] != INF && d[u]+w < d[v]) {
                d[v] = d[u]+w;
            }
        }
    }
    for (int i = 0; i < ed.size(); ++i) {
        int u = ed[i].s;
        int v = ed[i].e;
        int w = ed[i].val;
        if (d[u] != INF && d[u]+w < d[v]) {
            cout << -1 <<'\n';
            exit(0);
        }
    }
    cout << d[e];
}