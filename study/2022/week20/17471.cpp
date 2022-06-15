#include "bits/stdc++.h"

using namespace std;

int n;
int area[11];
vector<int> graph[11];


int calc(vector<int> &v1, vector<int> &v2) {
    int sum = 0;
    for (auto v: v1) {
        sum += area[v];
    }
    for (auto v: v2) {
        sum -= area[v];
    }
    return abs(sum);
}

bool check(vector<int> &v) {
    bool visited[11] = {false,};
    queue<int> q;
    q.push(v[0]);
    visited[v[0]] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int next: graph[now]) {
            if (!visited[next] && binary_search(v.begin(), v.end(), next)) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        if (!visited[v[i]]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int cnt, node;
    for (int i = 1; i <= n; ++i) {
        cin >> area[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> cnt;
        for (int j = 0; j < cnt; ++j) {
            cin >> node;
            graph[i].push_back(node);
        }
    }
    int ans = INT_MAX;
    for (int idx = 1; idx < (1 << n) - 1; idx++) {
        vector<int> v1, v2;
        for (int i = 0; i < n; ++i) {
            if (idx & 1 << i) {
                v1.push_back(i + 1);
            } else {
                v2.push_back(i + 1);
            }
        }
        if (check(v1) && check(v2)) {
            int res = calc(v1, v2);
            if (ans > res) {
                ans = res;
            }
        }
    }
    ans == INT_MAX ? cout << -1 : cout << ans;
}