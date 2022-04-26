#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    int alpha[26] = {0,};
    while (n--) {
        string str;
        cin >> str;
        reverse(str.begin(), str.end());
        int len = str.length();
        for (int i = 0, t = 1; i < len; ++i ,t*=10) {
            alpha[str[i] - 'A'] += t;
        }

    }
    sort(alpha, alpha + 26);
    for (int i = 0; i < 10; ++i) {
        ans += alpha[16 + i] * i;
    }
    cout << ans;
}