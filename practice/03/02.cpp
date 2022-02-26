#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> t(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    int res = 0;
    int i;
    for (i = n; i >= 4; i -= 2) {
        res += min(t[i] + t[1] + t[i - 1] + t[1], t[2] + t[2] + t[i] + t[1]);
    }
    if (i == 3) res += t[3] + t[1] + t[2];
    if (i == 2) res += t[2];
    cout << res;
}