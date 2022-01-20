#include "bits/stdc++.h"

using namespace std;

int arr[1001];
int dp[1001][31][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, w;
    cin >> t >> w;
    for (int i = 1; i <= t; ++i) {
        cin >> arr[i];
    }
    for (int i = 1; i <= t; ++i) {
        dp[i][0][1] = dp[i - 1][0][1] + (arr[i] == 1 ? 1 : 0);
        for (int j = 1; j <= w; ++j) {
            if (i < j) break;
            if (arr[i] == 1) { // 1번 나무에서 자두가 떨어짐
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + 1;
                dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][1]);
            } else {
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]);
                dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][1]) + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= w; ++i) {
        ans = max({dp[t][i][1], dp[t][i][2], ans});
    }
    cout << ans;

}