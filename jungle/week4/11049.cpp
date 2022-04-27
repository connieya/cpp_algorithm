#include "bits/stdc++.h"

using namespace std;

int arr[502][2];
int dp[502][502];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int end;
    cin >> end;
    for (int i = 0; i < end; ++i) {
        for (int j = 0; j < end; ++j) {
            dp[i][j]  = 1e9;
        }
    }
    for (int i = 0; i < end; ++i) {
        cin >> arr[i][0] >> arr[i][1];
        dp[i][i] = 0;
    }


    for (int len = 1; len < end; ++len ) {
        for (int start = 0; start < end - len; ++start) {
            for (int sep = 0; sep < len; ++sep) {
                dp[start][start+len] = min(dp[start][start+len],dp[start][sep]+dp[sep+1][start+len]+ arr[start][0]*arr[sep+1][0]*arr[start+len][1]);
                cout << dp[start][start+len] << '\n';
            }
        }
    }
    cout << dp[0][end - 1];
}