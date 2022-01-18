#include "bits/stdc++.h"

using namespace std;

int a[1000];
int d[1000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    d[0] = 1;
    int ans = d[0];
    for (int i = 1; i < n; ++i) {
        d[i] =1;
        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j] && d[j]+1 > d[i]) {
                    d[i] = d[j]+1;
            }
        }
        ans = max(ans, d[i]);
    }
    cout << ans;
}