﻿#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 0b1010;
    if (n &(1 << 3)) {
        cout << "3 th bit on !!" << '\n';
    }else {
        cout << "3 th bit off !!" << '\n';
    }

    if ( n &(1<<2)){
        cout << " 2 th bit on !!" << '\n';
    }else {
        cout << " 2 th bit off !! " << '\n';
    }
}