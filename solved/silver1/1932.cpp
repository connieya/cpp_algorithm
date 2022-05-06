﻿#include "bits/stdc++.h"

using namespace std;

int arr[501][501];
int dp[501][501];
int n;

int solve(int i, int j) {
    if (i == n-1) return arr[i][j];
    int &ret = dp[i][j];
    if (ret != -1) return ret;
    return ret = max(solve(i+1, j) , solve(i+1,j+1))+ arr[i][j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> arr[i][j];
        }
    }
    memset(dp,-1, sizeof(dp));
    cout << solve(0,0);
}