#include "bits/stdc++.h"

using namespace std;

int alpha[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;
        int len = input.length()-1;
        for (int j = 0; input[j]; ++j) {
            alpha[input[j]-'A'] += pow(10,len);
            len--;
        }
    }
    sort(alpha,alpha+26);
    int index = 9;
    int ans = 0;
    for (int i = 25; i >=0; --i) {
        if (!alpha[i]) break;
        ans += alpha[i]*index;
        index--;
    }
    cout << ans;

}