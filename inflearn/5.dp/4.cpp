#include "bits/stdc++.h"

using namespace std;

int arr[1000];
int dp[1000];

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
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = i-1; j >=0; --j) {
            if (arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(dp[i],ans);
    }
    cout << ans;
}