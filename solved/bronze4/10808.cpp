﻿#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int alpha[26] = {0};
    string str;
    cin >> str;
    for(auto ch : str){
        alpha[ch-'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        cout << alpha[i] << ' ';
    }
}