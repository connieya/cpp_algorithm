﻿#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long ans = 0;
    int n,num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        ans += num;
    }
    cout << ans;
}