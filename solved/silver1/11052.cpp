#include "bits/stdc++.h"

using namespace std;
int arr[1001];
int dp[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (dp[i] < arr[j]+dp[i-j]){
                dp[i] = arr[j]+dp[i-j];
            }
        }
    }
    cout << dp[n];



}