#include "bits/stdc++.h"

using namespace std;

int arr[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int locate = arr[0];
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] - locate > l - 1) {
            locate = arr[i];
            cnt++;
        }
    }
    cout << cnt;
}