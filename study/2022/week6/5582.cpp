#include "bits/stdc++.h"

using namespace std;
int dp[4001][4001];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a >> b;
    int a_len = a.size();
    int b_len = b.size();
    int ans = 0;
    for (int i = 0; i < a_len; ++i) {
        for (int j = 0; j < b_len; ++j) {
            if (a[i] == b[j]){
                if (i == 0 || j == 0){
                    dp[i][j] = 1;
                }else {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                ans = max(ans , dp[i][j]);
            }
        }
    }
    cout << ans;

}