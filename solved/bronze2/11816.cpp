﻿#include "bits/stdc++.h"

using namespace std;

int pow_(int num, int cnt) {
    if(cnt== 0) return 1;
    if (cnt == 1) return num;
    int n = pow_(num, cnt / 2);
    if (cnt % 2) {
        return num * n * n;
    }
    return n * n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    int ans = 0;

    if (str[0] == '0' && str[1] == 'x') {
        string t = "0123456789abcdef";
        for (int i = str.size() - 1, j = 0; str[i] != 'x'; i--, j++) {
            ans += pow_(16, j) * t.find(str[i]);
        }
        cout << ans;
    } else if (str[0] == '0' && str[1] != 'x') {
        for(int i= str.size()-1 , j= 0; i > 0; i--,j++) {
            ans += pow_(8,j)*(str[i]-'0');
        }
        cout << ans;

    } else {
        cout << str;
    }
}