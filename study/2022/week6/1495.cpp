#include "bits/stdc++.h"

using namespace std;

int n,s,m;
int arr[51];
int ans = 0;
void dfs(int L , int sum){
    if(L == n){
        ans = max(ans ,sum);
        return;
    }
    if (sum + arr[L] <= m){
        dfs(L+1,sum+arr[L]);
    }
    if (sum - arr[L] >= 0) {
        dfs(L+1, sum-arr[L]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dfs(0,s);
    if (ans == 0) {
        cout << -1;
    } else {
        cout << ans;
    }
}