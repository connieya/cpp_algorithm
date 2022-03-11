#include "bits/stdc++.h"

using namespace std;

int n,m;
int arr[8];
int ans[8];

void dfs(int L) {
    if (L == m){
        for (int i = 0; i < m; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
        if (tmp != arr[i]){
            ans[L] = arr[i];
            tmp = arr[i];
            dfs(L+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    dfs(0);
}