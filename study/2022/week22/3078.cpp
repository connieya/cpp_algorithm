﻿#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int n,k;
queue<int> q[21];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    string str;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        int len = str.size();
        while (!q[len].empty() && q[len].front() < i-k){
            q[len].pop();
        }
        ans += q[len].size();
        q[len].push(i);
    }
    cout << ans;
}