#include "bits/stdc++.h"

using namespace std;

int material[11][2];
long long ans = LONG_MAX;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int s, t;
        cin >> s >> t;
        material[i][0] = s, material[i][1] = t;
    }
    for (int i = 1; i < (1 << n); ++i) {
        int s = 1, t = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                s *= material[j][0];
                t += material[j][1];

            }
        }
        if (ans > abs(s-t)){
            ans = abs(s-t);
        }
    }
    cout << ans;
}