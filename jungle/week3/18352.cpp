#include "bits/stdc++.h"

#define INF 300001

using namespace std;
vector<int> graph[INF];
int dis[INF];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    fill(dis, dis + n + 1, -1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    dis[x] = 0;
    queue<int> Q;
    Q.push(x);
    while (!Q.empty()) {
        int s = Q.front();
        Q.pop();
        for (int n: graph[s]) {
            if (dis[n] == -1) {
                dis[n] = dis[s] + 1;
                Q.push(n);
            }
        }
    }
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        if (dis[i] == k) {
            cout << i << '\n';
            flag = false;
        }
    }
    if (flag) {
        cout << -1;
    }
}