#include "bits/stdc++.h"

#define INF 10001

using namespace std;
int n, m, k;
bool visited[INF];
int parent[INF];
int friend_cost[INF];

int find(int a) {
    if (a == parent[a]) {
        return a;
    }
    return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    // a 가 b보다 작다고 가정
    if (a > b) {
        swap(a, b);
    }
    parent[b] = a;
    friend_cost[a] = min(friend_cost[a], friend_cost[b]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> friend_cost[i];
        parent[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    for (int i = 1; i <= n; ++i) {
        if (!visited[find(i)]) {
            if (k < friend_cost[find(i)]) {
                cout << "Oh no";
                exit(0);
            }
            visited[find(i)] = true;
            ans += friend_cost[find(i)];
            k -= friend_cost[find(i)];
        }
    }
    cout << ans;
}