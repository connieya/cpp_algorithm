﻿#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    char before = '.';
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        if (before == 'E' && ch == 'W'){
            ans++;
        }
        before = ch;
    }
    cout << ans;

}