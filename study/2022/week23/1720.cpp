﻿#include "bits/stdc++.h"

using namespace std;

int dp[31];
int s[31];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    dp[1] = 1 , dp[2] = 3;
    for(int i=3; i<= 30; i++){
        dp[i] = dp[i-1] + dp[i-2]*2;
    }

    s[1]= 1 , s[2] = 3 , s[3] = 1 , s[4] = 5;
    for(int i=5; i<=30; i++) {
        s[i] = s[i-2]+ 2*s[i-4];
    }
    cout << (dp[n]-s[n]) /2 + s[n];
}