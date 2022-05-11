#include "bits/stdc++.h"

using namespace std;

int n, x;
int dp[65][65] = {1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> x;
            if (dp[i][j] == 0) continue;
            if (i + x < n) {
                dp[i + x][j] = 1;
            }
            if (j + x < n) {
                dp[i][j + x] = 1;
            }
        }
    }
    dp[n-1][n-1] ? cout << "HaruHaru" : cout << "Hing";

}