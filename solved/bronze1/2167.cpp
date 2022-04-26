#include "bits/stdc++.h"

using namespace std;

int arr[305][305];
int dp[305][305];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= m; ++i) {
        dp[1][i] = arr[1][i];
        for (int j = 2; j <= n; ++j) {
            dp[j][i] = arr[j][i]+dp[j-1][i];
        }
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int a1 ,b1, a2 ,b2;
        cin >> a1 >> b1 >> a2 >> b2;
        int ans = 0;
        for (int j = b1; j <=b2 ; ++j) {
            ans += dp[a2][j]-dp[a1-1][j];
        }
        cout << ans << '\n';
    }

}
