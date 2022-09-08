#include "bits/stdc++.h"
#define rank _rank
using namespace std;

int parent[1000001];
int rank[1000001];

int Find(int x){
    if(x == parent[x]) return x;
    return  parent[x] = Find(parent[x]);
}

void Union(int a ,int b){
    a = Find(a);
    b = Find(b);
    if(a == b) return;
    if(rank[a] < rank[b]) swap(a,b);
    parent[b] = a;
    if(rank[a] == rank[b]){
        rank[a] = rank[b] +1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        parent[i] =i;
    }
    for (int i = 0; i < m; ++i) {
        int a,b,c;
        cin >> a >> b >> c;
        if(a){
            if(Find(b) == Find(c)){
                cout << "YES\n";
            }else {
                cout << "NO\n";
            }
        }else {
            Union(b,c);
        }
    }

}