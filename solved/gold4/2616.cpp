#include "bits/stdc++.h"

using namespace std;

int arr[50001];
int prefix_sum[50001];
int dp[4][50001];
int n, m;

int dfs(int L , int start , int sum) {
    if (start+m  > n) return 0;
    cout << L << ' ' << sum <<  '\n';
    if (L == 3) {
        cout << "good " << sum << '\n';
        return sum;
    }

    return max(dfs(L,start+1,sum) ,dfs(L+1,start+m, sum+prefix_sum[m+start]-prefix_sum[start]));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int sum_prefix = 0;
    for (int i = 0; i < n; ++i) {
        sum_prefix += arr[i];
        prefix_sum[i + 1] = sum_prefix;
    }
    cin >> m;
    for (int i = 1; i <= 3; ++i) {
        for (int j = i * m; j <= n; ++j) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + (prefix_sum[j] - prefix_sum[j - m]));
        }
    }
    cout << dp[3][n] << '\n';

   cout <<  dfs(0,0,0);

}