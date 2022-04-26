#include "bits/stdc++.h"

using namespace std;

int alpha[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        int len = str.length();
        int num = 1;
        for (int j = len - 1; j >= 0; --j) {
            alpha[str[j] - 'A'] += num;
            num *= 10;
        }
    }
    sort(alpha,alpha+26);
    int ans = 0;
    int digit = 9;
    for (int i = 25; i >=0; --i) {
        if (alpha[i] == 0 ) break;
        ans += digit*alpha[i];
        digit--;
    }
    cout << ans;
}