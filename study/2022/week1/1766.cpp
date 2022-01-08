#include "bits/stdc++.h"

using namespace std;

int degree[32001];
vector<int> graph[32001];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a, b;
    priority_queue<int> pq;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        degree[b]++;
        graph[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i) {
        if (!degree[i]){
            pq.push(-i);
        }
    }
    while (!pq.empty()){
        int now = -pq.top();
        pq.pop();
        cout << now << ' ';
        for(int v : graph[now]){
            degree[v]--;
            if (!degree[v]){
                pq.push(-v);
            }
        }
    }
}