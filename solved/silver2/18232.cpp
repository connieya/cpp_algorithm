#include "bits/stdc++.h"

#define MAX 300001

using namespace std;

vector<int> teleport[MAX];
bool visited[MAX];

int dx[] = {-1, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, s, e, a, b;
    cin >> n >> m;
    cin >> s >> e;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        teleport[a].push_back(b);
        teleport[b].push_back(a);
    }
    queue<pair<int, int>> Q;
    Q.push({s, 0});
    visited[s] = true;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int point = cur.first;
        int time = cur.second;
        if (point == e) {
            cout << time;
            exit(0);
        }
        int len = teleport[point].size();
        for (int i = 0; i < 2; ++i) {
            int nxt = point + dx[i];
            if (nxt < 1 || nxt >= MAX) continue;
            if (!visited[nxt]) {
                visited[nxt] = true;
                Q.push({nxt, time + 1});
            }
        }

        if (len > 0) {
            for (int i = 0; i < len; ++i) {
                int nxt = teleport[point][i];
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    Q.push({nxt, time + 1});
                }
            }
            teleport[point].clear();
        }
    }
}