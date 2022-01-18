#include "bits/stdc++.h"

using namespace std;
const int MX = 1e6;
int a[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, n;
    cin >> m >> n;
    int start = 1, end = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > end) {
            end = a[i];
        }
    }
    while (start <= end) {
        int mid = (start + end) / 2;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i] / mid;
        }
        if (sum <  m){
            end = mid -1;
        }else {
            start = mid +1;
            ans = mid;
        }
    }
    cout << ans;
}