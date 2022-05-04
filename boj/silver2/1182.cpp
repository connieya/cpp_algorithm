#include "bits/stdc++.h"

using namespace std;

int n,m;
int arr[21];

int dfs(int L , int sum){
    if (L == n) {
        if (sum == m) {
            return 1;
        }
        return 0;
    }
    int cnt = 0;
    cnt += dfs(L+1,sum);
    cnt += dfs(L+1,sum+arr[L]);
    return cnt;
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
    int res = dfs(0,0);
    if (m==0) res--;
    cout << res;

}