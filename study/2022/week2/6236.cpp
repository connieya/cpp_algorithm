#include "bits/stdc++.h"

using namespace std;

int arr[100001];
int n, m;

bool func(int mid) {
    int k = mid;
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        if (mid < arr[i]) {
            return false;
        }
        if (k - arr[i] < 0) {
            k = mid;
            cnt++;
        }
        k = k - arr[i];
    }
    return m >= cnt;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long end = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        end += arr[i];
    }
    int start = 0;
    int result = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (func(mid)) {
            end = mid - 1;
            result = mid;
        } else {
            start = mid + 1;
        }
    }
    cout << result;
}