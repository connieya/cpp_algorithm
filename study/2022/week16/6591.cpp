#include "bits/stdc++.h"

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1) {
        int n, k;
        long long ans = 1;
        cin >> n >> k;
        if (!n && !k) break;
        k = min(n - k, k);
        for (int i = 1; i <= k; ++i) {
            ans *= n;
            ans /= i;
            n--;
        }
        cout << ans << '\n';
    }

}