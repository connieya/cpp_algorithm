#include "bits/stdc++.h"

typedef long long ll;

using namespace std;

ll arr[10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    ll ans = 0;
    for (int i = 1; i < 1 << n; ++i) {
        ll v = 1;
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                v *= arr[j];
                cnt++;
            }
        }
        if (cnt % 2) {
            ans += m / v;
        } else {
            ans -= m / v;
        }
    }
    cout << ans;
}