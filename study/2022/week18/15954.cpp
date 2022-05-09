#include "bits/stdc++.h"

using namespace std;

int arr[501];
int n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    double ans = INT_MAX;
    for (int i = k; i <= n; ++i) {
        for (int j = 0; j <= n - i; ++j) {
            double sum = 0;
            for (int l = j; l < j+i ; ++l) {
                sum += arr[l];
            }
            double avg = sum/i;
            double d_sum = 0;
            for (int l = j; l < j+i ; ++l) {
                d_sum += (arr[l]-avg)*(arr[l]-avg);
            }
            ans = min(ans,sqrt(d_sum/i));
        }
    }
    cout.precision(10);
    cout << ans;

}