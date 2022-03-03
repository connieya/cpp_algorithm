#include "bits/stdc++.h"

using namespace std;

bool visited[501];
int p[501];
vector<int> tree[501];
bool isTree;

void dfs(int parent, int prev) {
    if (visited[parent]) {
        isTree = false;
        return;
    }
    visited[parent] = true;
    for (int child: tree[parent]) {
        if (child == prev) continue;
        dfs(child, parent);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int node, edge;
    int idx = 1;
    while (1) {
        cin >> node >> edge;
        if (node + edge == 0) break;
        fill(p, p + 501, 0);
        for (int i = 1; i <= 500; ++i) {
            tree[i].clear();
            visited[i] = false;
        }
        for (int i = 0; i < edge; ++i) {
            int a, b;
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        int cnt = 0;
        for (int i = 1; i <= node; ++i) {
            if (!visited[i]) {
                isTree = true;
                dfs(i, -1);
                if (isTree) {
                    cnt++;
                }
            }
        }
        cout << "Case " << idx++ << ": ";
        if (cnt == 0) {
            cout << "No trees." << '\n';
        } else if (cnt == 1) {
            cout << "There is one tree." << '\n';
        } else {
            cout << "A forest of " << cnt << " trees." << '\n';
        }
    }
}