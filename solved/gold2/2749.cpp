﻿#include "bits/stdc++.h"
typedef long long ll;

using namespace std;

ll fibo[1500000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fibo[0] = 0 , fibo[1] = 1;
    for(int i=2; i<= 1500000; i++){
        fibo[i] = fibo[i-1]+fibo[i-2];
        fibo[i] %= 1000000;
    }
    ll n;
    cin >> n;
    cout << fibo[n%1500000];
}