#include "bits/stdc++.h"

using namespace std;

int arr[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, v;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> v;
        cout << binary_search(arr,arr+n,v) << '\n';
    }
}