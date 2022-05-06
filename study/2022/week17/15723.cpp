﻿#include "bits/stdc++.h"

using namespace std;

bool checked[27][27];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    char a, c;
    string b;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        checked[a-'a'][c-'a'] = 1;

    }
    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (checked[i][k] && checked[k][j]){
                    checked[i][j] = true;
                }
            }
        }
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        checked[a-'a'][c-'a'] ? cout << "T" << '\n' :  cout << "F" << '\n';
    }
}