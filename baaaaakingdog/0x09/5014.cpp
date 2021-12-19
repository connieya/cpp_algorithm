#include "bits/stdc++.h"

using namespace std;
int f, s, g, u, d;
int dist[1000002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> f >> s >> g >> u >> d;
    fill(dist + 1, dist + f + 1, -1);
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt: {cur + u, cur - d}) {
            if (nxt >= 1 && nxt <= f && dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
    if (dist[g] == -1) {
        cout << "use the stairs";
    } else {
        cout << dist[g];
    }
}