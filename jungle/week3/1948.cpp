#include "bits/stdc++.h"

using namespace std;
vector<pair<int, int>> graph[10001];

int start, e;
int depth = -1;

int dfs(int s, int sum, int L) {
    int cost = sum;
    if (s == e) {
        if (L > depth) {
            depth = L;
        }
        return sum;
    }
    for (auto next: graph[s]) {
        cost = max(cost, dfs(next.first, sum + next.second, L + 1));
    }
    return cost;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    cin >> start >> e;
    cout << dfs(start, 0, 0) << '\n';
    cout << depth+1;
}