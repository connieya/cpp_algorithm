#include "bits/stdc++.h"

#define INF 1000000000

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long x, y;
    cin >> x >> y;
    int z = (y * 100) / x;
    if (z >= 99) {
        cout << -1;
        return 0;
    }
    int ans = -1;
    int lt = 0, rt = INF;
    while (lt <= rt) {
        int mid = (lt + rt) / 2;
        if (100 * (y + mid) / (x + mid) <= z) {
            lt = mid + 1;
            ans = mid + 1;
        } else {
            rt = mid - 1;
        }
    }
    cout << ans;
}