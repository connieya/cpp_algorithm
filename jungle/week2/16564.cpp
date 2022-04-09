#include "bits/stdc++.h"

#define MAX 1000001
using namespace std;
typedef unsigned long long Ull;

int arr[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    Ull k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    Ull lt = 1, rt = arr[n - 1] * k;
    Ull ans = 0;
    while (lt <= rt) {
        Ull mid = (lt + rt) / 2;
        Ull sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mid >= arr[i]) {
                sum += mid - arr[i];
            }
        }
        if (sum <= k) {
            lt = mid + 1;
            ans = mid;
        } else {
            rt = mid - 1;
        }
    }
    cout << ans;
}