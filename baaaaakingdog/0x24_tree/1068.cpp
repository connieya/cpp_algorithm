#include "bits/stdc++.h"

using namespace std;

vector<int> tree[51];
int e;

int dfs(int start) {
    int child = 0;
    int leaf = 1;
    for (int next: tree[start]) {
        if (next == e) continue;
        child += dfs(next);
    }
    if (child) return  child;
    return leaf;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , root;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        if (v == -1) {
            root = i;
            continue;
        }
        tree[v].push_back(i);
    }
    cin >> e;
    if (root == e){
        cout << 0;
    }else {
        cout << dfs(root);
    }
}

