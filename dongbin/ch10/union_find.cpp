#include "bits/stdc++.h"

using namespace std;

int unf[10000];

int find(int a){
    if (a == unf[a]){
        return a;
    }
    return unf[a] = find(unf[a]);
}

void Union(int a ,int b){
    int aa = find(a);
    int bb = find(b);
    if (aa > bb){
        unf[aa] = bb;
    }else {
        unf[bb] = aa;
    }
}


int main(void) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        unf[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int a ,b;
        cin >> a >> b;
        Union(a,b);
    }
    cout << "print ~~ : ";
    for (int i = 1; i <=n ; ++i) {
        cout << unf[i] << ' ';
    }
    cout << '\n';

    cout << "parent print ~~ : ";
    for (int i = 1; i <=n ; ++i) {
        cout << find(i) << ' ';
    }

}