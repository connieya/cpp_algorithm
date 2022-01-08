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

int arr[500][500];

int main()
{
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            if (arr[i][j]){
                Union(i+1,j+1);
            }
        }
    }
    int pre;
    bool flag = true;
    cin >> pre;
    for (int i = 1; i < m; ++i) {
        int v;
        cin >> v;
        if (find(pre) != find(v)){
            flag = false;
        }
        pre = v;
    }
    if (!flag){
        cout << "NO";
    }else {
        cout << "YES";
    }
}