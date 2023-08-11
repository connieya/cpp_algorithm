﻿#include "bits/stdc++.h"

using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    int alpha[26] = {0};

    for(auto ch : str){
        alpha[ch-'A']++;
    }
    int odd = 0;
    int idx = -1;
    for(int i=0; i<26; i++){
        if(alpha[i] && alpha[i]%2){
            odd++;
            idx = i;
        }
    }
    if(odd > 1){
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    string a ,b;
    for (int i = 0; i < 26; ++i) {
        if(!alpha[i]) continue;
        for (int j = 0; j < alpha[i]/2; ++j) {
            a += (char)(i+'A');
            b = (char)(i+'A') +b;
        }
    }
    cout << a;
    if (odd){
        cout << (char)(idx+'A');
    }
    cout <<b;
}
