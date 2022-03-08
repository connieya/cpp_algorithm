#include "bits/stdc++.h"

using namespace std;

int parent[1001];

int find(int a){
    if (a == parent[a]){
        return a;
    }
    return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b){
        parent[a] = b;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,a,b;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        parent[i] =i;
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        Union(a,b);
    }
    cin >> a >> b;
    if (find(a) != find(b)){
        cout << "NO" << '\n';
    }else {
        cout << "YES" << '\n';
    }
    for (int i = 1; i <= n; ++i) {
        cout << parent[i] << ' ';
    }
    cout << '\n';

}