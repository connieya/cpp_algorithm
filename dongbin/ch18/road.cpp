#include "bits/stdc++.h"

using namespace std;

 int parent[1000];
 int find(int a);
 void Union(int a , int b);

 int find(int a){
     if (a == parent[a]){
         return a;
     }
     return parent[a] = find(parent[a]);
 }

 void Union(int a ,int b){
     int aa = find(a);
     int bb = find(b);
     parent[aa] = bb;
 }

vector<pair<int ,pair<int , int>>> graph;
 int main()
 {
     int n,m ,total = 0;
     cin >> n >> m;
     for (int i = 0; i < n; ++i) {
         parent[i] = i;
     }
     for (int i = 0; i < m; ++i) {
         int a,b, cost;
         cin >> a >> b >>cost;
         total += cost;
         graph.push_back({cost , {a,b}});
     }
     sort(graph.begin(),graph.end());
     int min_cost = 0;
     for (int i = 0; i < graph.size(); ++i) {
         int cost = graph[i].first;
         int x = graph[i].second.first;
         int y = graph[i].second.second;
         if (find(x) != find(y)){
             min_cost += cost;
             Union(x,y);
         }
     }
     cout << total - min_cost;
 }