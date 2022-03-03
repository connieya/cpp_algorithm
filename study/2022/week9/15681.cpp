#include "bits/stdc++.h"

using namespace std;


vector<int> tree[100001];
bool visited[100001];
int d[100001];

int dfs(int parent) {

    visited[parent] = true;
    int cnt = 1;
    for (int child: tree[parent]) {
        if (!visited[child]) {
            cnt += dfs(child);
        }
    }
    return d[parent] = cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, root, q;
    cin >> n >> root >> q;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(root);
    for (int i = 0; i < q; ++i) {
        int node;
        cin >> node;
        cout << d[node] << '\n';
    }
}