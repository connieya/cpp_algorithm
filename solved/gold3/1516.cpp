#include "bits/stdc++.h"

using namespace std;

int indegree[501];
vector<int> graph[501];
int ans[501];
int tmp[501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int time, node;
        cin >> time;
        ans[i] = time;
        while (1) {
            cin >> node;
            if (node == -1) break;
            graph[node].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int next: graph[now]) {
            indegree[next]--;
            tmp[next] = max( tmp[next], ans[now]);
            if (indegree[next] == 0) {
                ans[next] += tmp[next];
                q.push(next);
            }
        }
    }
    for (int j = 1; j <= n; ++j) {
        cout << ans[j] << '\n';
    }

}