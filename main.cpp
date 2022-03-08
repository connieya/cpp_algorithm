#include "bits/stdc++.h"

using namespace std;

int n,m;
int arr[21];

int dfs(int L , int sum) {
    if (L == n){
        if (sum == m) return 1;
        return 0;
    }
    return dfs(L+1,sum+arr[L]) + dfs(L+1,sum);
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
    dfs(0,0);
    if (m == 0) {
        cout << dfs(0,0)-1;
    }else {
        cout << dfs(0,0);
    }
}