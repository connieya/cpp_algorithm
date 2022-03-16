#include "bits/stdc++.h"

using namespace std;

int parent[1000001];
int cnt[1000001];

int find(int a){
    if (a == parent[a] ) return a;
    return parent[a] = find(parent[a]);
}

void Union(int a, int b)  {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[a] = b;
        cnt[b] += cnt[a];
        cnt[a] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,a,b;
    char op;
    cin >> n;
    for (int i = 1; i <= 1000000; ++i) {
        parent[i] = i;
        cnt[i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        cin >> op;
        if (op == 'I'){
            cin >> a >> b;
            if (find(a) != find(b)){
                Union(a,b);
            }
        }else {
            cin >> a;
            cout << cnt[find(a)] << '\n';
        }
    }

}