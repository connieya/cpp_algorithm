﻿#include "bits/stdc++.h"

using namespace std;

int dp[100001];
int arr[100001];

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

    dp[0] = arr[0];
    int ans = dp[0];
    for (int i = 1; i < n; ++i) {
        if(arr[i] < arr[i]+dp[i-1]){
            dp[i] = arr[i]+dp[i-1];
        }else {
            dp[i] = arr[i];
        }
        ans = max(ans ,dp[i]);
    }
    cout << ans;
}