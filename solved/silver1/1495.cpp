#include "bits/stdc++.h"

using namespace std;

int n, s, m, ans = -1;
int arr[52];
bool dp[51][1001];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    dp[0][s] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if(dp[i-1][j]){

            }
        }
    }
    ans == -1 ? cout << -1 : cout << ans;

}