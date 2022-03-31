#include "bits/stdc++.h"

#define MAX 10001
using namespace std;

vector<pair<int, int>> tree[MAX];
bool visited[MAX];
int len = 0, endPoint;

void dfs(int start, int edge) {
    visited[start] = true;
    if (edge > len) {
        len = edge;
        endPoint = start;
    }
    for (auto nxt: tree[start]) {
        if (!visited[nxt.first]) {
            dfs(nxt.first, edge + nxt.second);
        }
    }
    visited[start] = false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    dfs(1, 0);
    len = 0;
    dfs(endPoint, 0);
    cout << len;
}