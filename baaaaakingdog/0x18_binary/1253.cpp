#include "bits/stdc++.h"

using namespace std;

int arr[2000];

bool binary_search(int target, int start, int end , int i, int j) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == target) {
            if (i==mid || j==mid) return false;
            return true;
        }
        if (arr[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    map<long long ,long long > m;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (binary_search(arr[i] + arr[j], 0, n - 1 , i ,j)) {
                m[arr[i]+arr[j]]++;
                if (m[arr[i]+arr[j]] == 1){
                    ans++;
                }
            }
        }
    }
    cout << ans;
}