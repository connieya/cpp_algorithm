#include "bits/stdc++.h"

using namespace std;

int parent[1001];
int find(int a);
void Union(int a , int b);

int find(int a){
    if (a == parent[a]){
        return a;
    }
    return parent[a] = find(parent[a]);
}

void Union(int a ,int b){
     a = find(a);
     b = find(b);
    parent[a] = b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<pair<int ,pair<int ,int>>> graph;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cost;
            cin >> cost;
            if (i==j) continue;
            graph.push_back({cost ,{i,j}});
        }
    }
    sort(graph.begin(), graph.end());
    long long ans = 0;
    int cnt = 0;
    int len =graph.size();
    for (int i = 0; i < len; ++i) {
        int a =graph[i].second.first;
        int b = graph[i].second.second;
        if (find(a) != find(b)) {
            Union(a,b);
            ans += graph[i].first;
            cnt++;
        }
        if (cnt == n-1) break;
    }
    cout << ans;
}

