#include "bits/stdc++.h"

using namespace std;

int indegree[10001];
int T[10001];
vector<int> graph[10001];
int ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int t , cnt;
        cin >> t >> cnt;
        T[i] = t;
        indegree[i] += cnt;
        for (int j = 0; j < cnt; ++j) {
                int node;
                cin >> node;
                graph[node].push_back(i);
        }
    }
    priority_queue<pair<int , int>> pq;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            pq.push({-T[i],i});
        }
    }
    while (!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        int time = -cur.first;
        int now = cur.second;
        ans = time;
        for (int next: graph[now]) {
            indegree[next]--;
            if (indegree[next] == 0){
                pq.push({ -(time+T[next]) , next});
            }
        }
    }
    cout << ans;
}