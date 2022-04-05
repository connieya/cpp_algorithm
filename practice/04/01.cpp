#include "bits/stdc++.h"

using namespace std;

int arr[101];
int dp[101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int p = 1000;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 1 ){
            p = 1;
        }else {
            dp[i] = p++;
        }
    }
    p = 1000;
    for (int i = n-1; i >= 0; --i) {
        if (arr[i] == 1){
            p = 1;
        }else {
            if (dp[i] > p){
                dp[i] = p++;
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
}