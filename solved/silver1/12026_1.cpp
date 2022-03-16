#include "bits/stdc++.h"

#define INF 2147000000
using namespace std;

long long dp[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string str;
    cin >> str;
    for (int i = 0; i < n; ++i) {
        dp[i] = INF;
    }
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'B') {
            for (int j = i + 1; j < n; ++j) {
                if (str[j] == 'O') {
                    dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));
                }
            }
        } else if (str[i] == 'O') {
            for (int j = i + 1; j < n; ++j) {
                if (str[j] == 'J') {
                    dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));
                }
            }
        } else if (str[i] == 'J') {
            for (int j = i + 1; j < n; ++j) {
                if (str[j] == 'B') {
                    dp[j] = min( dp[j], dp[i] + (j - i) * (j - i) );
                }
            }
        }
    }
    if (dp[n - 1] == INF) {
        cout << -1;
    } else {
        cout << dp[n - 1];
    }
}