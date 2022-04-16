#include "bits/stdc++.h"

#define MAX 100001

using namespace std;

vector<pair<int, int>> connect;
bool visited[MAX];
stack<int> disconnect;
int parent[MAX];
long long cost[MAX];

int find(int a) {
    if (a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a < b) {
        parent[b] = a;
        cost[a] += cost[b];
        cost[b] = 0;
    } else {
        parent[a] = b;
        cost[b] += cost[a];
        cost[a] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        connect.push_back({a, b});
    }
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        cost[i] = 1;
    }
    for (int i = 0; i < q; ++i) {
        int d;
        cin >> d;
        visited[d - 1] = true;
        disconnect.push(d - 1);
    }
    for (int i = 0; i < connect.size(); ++i) {
        if (visited[i]) continue;
        int a = connect[i].first;
        int b = connect[i].second;
        if (find(a) != find(b)){
            Union(a, b);
        }

    }
    long long ans = 0;
    while (!disconnect.empty()) {
        int node = disconnect.top();
        disconnect.pop();
        int x = connect[node].first;
        int y = connect[node].second;
        int nx = find(x);
        int ny = find(y);
        if (nx != ny){
            ans += (cost[nx] * cost[ny]);
            Union(x, y);
        }

    }
    cout << ans;

}