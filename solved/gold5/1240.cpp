﻿#include "bits/stdc++.h"

using namespace std;

vector<pair<int, int>> graph[1001];

void dfs(int start, int prev, int des, int dis) {
    if (start == des) {
        cout << dis << '\n';
        return;
    }
    for (auto next: graph[start]) {
        if (next.first == prev) continue;
        dfs(next.first, start, des, dis + next.second);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        dfs(a, -1, b, 0);
    }
}