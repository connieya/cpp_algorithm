#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string input;
    cin >> input;
    int len = input.length();
    int a = 0 , b =0;
    int i;
    for ( i = 0; i < len / 2; ++i) {
        a += input[i]-'0';
    }
    for (; i < len; ++i) {
        b += input[i]-'0';
    }
    if (a==b){
        cout << "LUCKY";
    }else {
        cout << "READY";
    }
}