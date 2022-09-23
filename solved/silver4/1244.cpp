﻿#include "bits/stdc++.h"

using namespace std;

bool light[101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,gender,num;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> light[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> gender >> num;
        if(gender == 1){
            for (int j = num; j <= n; j+=num) {
                light[j] = !light[j];
            }
        }else {
            int x = num , y = num;
            light[num] = !light[num];
            while (--x > 0 && ++y <= n && light[x] == light[y]){
                light[x] = !light[x];
                light[y] = !light[y];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << light[i] << ' ';
        if(i % 20 == 0){
            cout << '\n';
        }
    }
}