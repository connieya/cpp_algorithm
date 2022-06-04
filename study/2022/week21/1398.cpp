#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
int dp[100];



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; i+10*j < 100 ; ++j) {
            for (int k = 0; i+10*j+25*k < 100; ++k) {
                const int val = i+10*j+25*k;
                dp[val] = min(dp[val] , i+j+k);
            }
        }
    }
    int t, ans;
    ll price;
    cin >> t;
    while (t--) {
        cin >> price;
        ans = 0;
        while (price) {
            ans += dp[price % 100];
            price /= 100;
        }
        cout << ans << '\n';
    }
}