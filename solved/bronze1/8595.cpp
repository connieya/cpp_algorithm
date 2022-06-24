#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long ans = 0;
    long long res = 0;
    int n;
    string str;
    cin >> n >> str;
    for (char ch: str) {
        if (isdigit(ch)) {
            res = res * 10 + (ch - '0');
        } else {
            ans += res;
            res = 0;
        }
    }
    cout << ans+res;
}
