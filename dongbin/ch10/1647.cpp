#include "bits/stdc++.h"

using namespace std;

int parent[100001];

int find(int a);
void Union(int a, int b);
bool isSameParent(int x , int y);


vector<pair<int ,pair<int,int>>> edges;
vector<int> V;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c,{a,b}});
    }
    sort(edges.begin(),edges.end());
    int ans = 0;
    for (int i = 0; i < edges.size(); ++i) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(!isSameParent(a,b)){
            Union(a,b);
            V.push_back(cost);
        }
    }
    for (int i = 0; i < V.size()-1; ++i) {
        ans += V[i];
    }
    cout << ans <<'\n';
}

int find(int a) {
    if (a == parent[a]) {
        return a;
    }
    return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    parent[aa] = bb;
}

bool isSameParent(int x, int y) {
    return find(x) == find(y);
}