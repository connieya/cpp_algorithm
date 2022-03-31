#include "bits/stdc++.h"
#define INF 1000001
using namespace std;

int parent[INF];
int find(int a);
void Union(int a , int b);

int find(int a){
    if (a == parent[a]){
        return a;
    }
    return parent[a] = find(parent[a]);
}

void Union(int a ,int b){
        a = find(a);
        b = find(b);
        if(a != b) {
            parent[a] = b;
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        parent[i] =  i;
    }
    for (int i = 0; i < m; ++i) {
        int a,b,c;
        cin >> a >> b >>c;
        if (a){
            if (find(b) == find(c)){
                cout << "YES" << '\n';
            }else {
                cout << "NO" << '\n';
            }
        }else {
            Union(b,c);
        }
    }
}