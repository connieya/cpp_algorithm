#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, ans = 0, i;
    cin >> n >> k;
    while (1) {
        for (i = 1; i < n; i *= 2) {

        }
        if (i == n) {
            break;
        } else if (1 < k) {
            n = n - i / 2;
            k--;
        } else if (k == 1) {
            ans = i - n;
            break;
        }
    }
    cout << ans;
}