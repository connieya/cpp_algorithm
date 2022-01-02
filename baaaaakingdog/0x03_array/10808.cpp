#include "bits/stdc++.h"

using namespace std;
int alpha[26];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for(auto ch : s){
        alpha[ch-'a']++;
    }
    for (int a: alpha) {
        cout << a <<' ';
    }
}