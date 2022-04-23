#include "bits/stdc++.h"

using namespace std;

int board[1001][1001];
int dp[1001][1001];
int ans[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a = 0, b = 0, c = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); ++j) {
            board[i][j] = str[j] - '0';
        };
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 0)continue;
            a = b = c = 0;
            if (i - 1 >= 0) a = board[i - 1][j];
            if (j - 1 >= 0) b = board[i][j - 1];
            if (i - 1 >= 0 && j - 1 >= 0)c = board[i - 1][j - 1];
            int min_value = min(a, min(b, c));
            board[i][j] = min_value + 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 1; k <= board[i][j]; ++k) {
                ans[k]++;
            }
        }
    }
    int mx = max(n, m);
    for (int i = 1; i <= mx; ++i) {
        if (ans[i] == 0) break;
        cout << i << ' ' << ans[i] << '\n';
    }
}