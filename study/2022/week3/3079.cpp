#include "bits/stdc++.h"

using namespace std;
const int MX = 1e5;
int friends[MX];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    long long end = 0;
    for (int i = 0; i < n; ++i) {
        cin >> friends[i];
        if (friends[i] > end) {
            end = friends[i];
        }
    }
    end *= m;
    long long ans = 0;
    long long start = 0;
    while (start <= end) {
        long long mid = (end + start) / 2;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += mid / friends[i];
        }
        if (sum >= m) {
            end = mid - 1;
            ans = mid;
        } else {
            start = mid + 1;
        }
    }
    cout << ans;
}