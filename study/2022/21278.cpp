#include "bits/stdc++.h"

#define INF 101

using namespace std;

vector<int> graph[INF];
int dist[INF][INF];
int n, m;


void bfs(int s) {
    for (int i = 1; i <= n; ++i) {
        dist[s][i] = -1;
    }
    dist[s][s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        for (int next : graph[now]) {
            if (dist[s][next] == -1){
                dist[s][next] = dist[s][now]+1;
                Q.push(next);
            }
        }
    }
}


void solve() {
    int ans_x, ans_y, ans = 0x7fffffff;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int sum = 0;
            for (int k = 1; k <= n; ++k) {
                sum += min(dist[i][k], dist[j][k]) * 2;
            }
            if (ans > sum) {
                ans = sum;
                ans_x = i;
                ans_y = j;
            }
        }
    }
    cout << ans_x << ' ' << ans_y << ' ' << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        bfs(i);
    }
    solve();
}