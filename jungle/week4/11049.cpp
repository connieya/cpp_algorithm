#include "bits/stdc++.h"

using namespace std;

int arr[502][2];
int dp[502][502];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i][0] >> arr[i][1];
    }
    for (int i = 1; i < n; ++i) {
        dp[i][i + 1] = arr[i][0] * arr[i][1] * arr[i + 1][1];
    }
    for (int m = 2; m <= n; ++m) {
        for (int i = 1; i <= n - m; ++i) {
            int j = i + m;
            for (int k = i; k < j; ++k) {
                int res = dp[i][k] + dp[k + 1][j] + arr[i][0] * arr[k][1] * arr[j][1];
                if (!dp[i][j] || dp[i][j] > res){
                    dp[i][j]  = res;
                }
            }
        }
    }
    cout << dp[1][n];

}