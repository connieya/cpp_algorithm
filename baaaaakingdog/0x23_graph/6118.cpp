#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<int> graph[20001];
    for (int i = 0; i < m; ++i) {
        int a , b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<pair<int ,int>> Q;
    Q.push({1,0});
    int d[20001] = {-1,-1,0};
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int vertex = cur.first;
        int dis = cur.second;
        for (int next: graph[vertex]) {
            if (d[next] == 0 ){
                d[next] = dis+1;
                Q.push({next,dis+1});
            }
        }
    }
    int MX = d[1];
    int cnt = 0;
    int num = 0;
    for (int i = 2; i <= n; ++i) {
        if (d[i] > MX) {
            MX = d[i];
            num = i;
            cnt =0;
            cnt++;
        } else if (d[i] == MX) {
            cnt++;
        }
    }
    cout << num << ' ' << MX << ' ' << cnt;
}