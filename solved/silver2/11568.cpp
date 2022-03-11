#include "bits/stdc++.h"

using namespace std;

int arr[1001];
int dp[1001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , ans = -1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = i-1; j >= 0; --j) {
            if (arr[i] > arr[j] && dp[j]+1 > dp[i]) {
                dp[i] = dp[j]+1;
            }
        }
        if (dp[i] > ans){
            ans = dp[i];
        }
    }
    cout << ans;
}