#include "bits/stdc++.h"

using namespace std;

int n, s, m, ans = -1;
int arr[52];
int dp[51][2];

void dfs(int volume, int L) {
    if (L == n) {
        ans = max(ans, volume);
        return;
    }

    if (volume + arr[L] <= m) {
        dfs(volume + arr[L], L + 1);
    }
    if (volume - arr[L] >= 0) {
        dfs(volume - arr[L], L + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dp[0][0] = dp[0][1] = s;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i-1][0]+arr[i-1];
        dp[i][0] = dp[i-1][1]+arr[i-1];
        dp[i][1] = dp[i-1][0]-arr[i-1];
        dp[i][1] = dp[i-1][1]-arr[i-1];
    }
    dfs(s, 0);
    ans == -1 ? cout << -1 : cout << ans;

}