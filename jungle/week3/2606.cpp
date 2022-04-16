#include "bits/stdc++.h"

using namespace std;
vector<int> graph[101];
bool checked[101];

void dfs(int start, int prev) {
    checked[start] = true;
    cout << start << '\n';
    for (int nxt: graph[start]) {
        if (prev == nxt)continue;
        dfs(nxt, start);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 1);
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        ans += checked[i];

    }
    cout << ans;

}