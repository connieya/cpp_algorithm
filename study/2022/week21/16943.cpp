#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    string ans = "0";
    do {
        if (a[0] != '0' && a.compare(b) < 0) {
            if (a.compare(ans) > 0) {
                ans = a;
            }
        }
    } while (next_permutation(a.begin(), a.end()));

    cout << (ans == "0" ? "-1" : ans);
}