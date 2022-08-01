#include "bits/stdc++.h"

using namespace std;

int board[1001];
int dp[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
        dp[i] = board[i];
    }
    int ans = dp[0];
    for (int i = 1; i < n; ++i) {
        for (int j = i-1; j >=0 ; --j) {
            if(board[i] > board[j]){
                dp[i] = max(dp[i],board[i]+dp[j]);
            }
        }

        if(dp[i] > ans){
           ans = dp[i];
        }
    }
    cout << ans;
}