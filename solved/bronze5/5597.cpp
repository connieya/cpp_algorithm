﻿#include "bits/stdc++.h"

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool student[31] = {false,};
    for (int i = 0; i < 28; ++i) {
        int num;
        cin >> num;
        student[num] = 1;
    }
    for (int i = 1; i <= 30; ++i) {
        if(!student[i]){
            cout << i << '\n';
        }
    }
}