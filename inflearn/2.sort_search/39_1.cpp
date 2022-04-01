#include "bits/stdc++.h"

using namespace std;

int a[100] , b[100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int i = 0 ,j = 0;
    while (i < n && j < m){
        if (a[i] < b[j]){
            cout << a[i++] << ' ';
        }else {
            cout << b[j++] << ' ';
        }
    }
    while (i<n){
        cout << a[i++] << ' ';
    }
    while (j<m) {
        cout << b[j++] << ' ';
    }
}