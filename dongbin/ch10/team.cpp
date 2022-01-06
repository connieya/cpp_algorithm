#include "bits/stdc++.h"

using namespace std;

int parent[1000];
int find(int a);
void Union(int a , int b);

int find(int a){
    if (a == parent[a]){
        return a;
    }
    return parent[a] = find(parent[a]);
}

void Union(int a ,int b){
    int aa = find(a);
    int bb = find(b);
    parent[aa] = bb;
}

int main()
{
    int n,m;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int a ,b ,c;
        cin >> a >> b >> c;
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