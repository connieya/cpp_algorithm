#include "bits/stdc++.h"

using namespace std;

bool dp[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    dp[1] = true, dp[2] = false, dp[3] = true, dp[4] = true;
    for (int i = 5; i <= 1000; ++i) {
        dp[i] = !(dp[i-1] && dp[i-3] && dp[i-4]);
    }
    string answer = dp[n] ? "SK" : "CY";
    cout << answer;
}
