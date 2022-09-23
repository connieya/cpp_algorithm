﻿#include "bits/stdc++.h"

using namespace std;

char star[400][400];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    n = 4*(n-1)+1;
    for (int i = 0; i <= n/2; i+=2) {
        int l = n- i*2;
        for (int j = 0; j < l; ++j) {
            star[i+j][i] = star[i][i+j] = star[i+l-1][i+j] = star[i+j][i+l-1] = '*';

        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(star[i][j] == '*') cout << "*";
            else cout << ' ';
        }
        cout << '\n';
    }
}