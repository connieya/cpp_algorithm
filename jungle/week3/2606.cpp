#include "bits/stdc++.h"

using namespace std;

int parent[101];

int Find(int x){
    if(x == parent[x]) return  x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x > y) swap(x,y);
    parent[y] = x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        Union(a,b);
    }
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        ans += (Find(i) == 1);
    }
    cout << ans;
}