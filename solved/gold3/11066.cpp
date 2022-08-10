#include "bits/stdc++.h"

using namespace std;

int n;
int arr[502];
int sum[502];
int dp[502][502];

int solve(int i, int j) {
    if(i==j) return 0;
    if(i+1 == j) return arr[i]+arr[j];
    int &ans = dp[i][j];
    if(ans != -1) return ans;
    ans = int(1e9);
    for(int k=i; k<j; k++){
       ans = min(ans, solve(i,k)+ solve(k+1,j));
    }
    return ans+=sum[j]-sum[i-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(dp,-1, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
            sum[i] = sum[i-1]+arr[i];
        }
        cout << solve(1,n) << '\n';
        memset(sum,0, sizeof(sum));
    }
}