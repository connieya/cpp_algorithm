#include "bits/stdc++.h"

using namespace std;

int arr[200001];

int Bin(int lt, int rt, int target) {
    int ret = -1;
    while (lt <= rt) {
        int mid = (lt + rt) / 2;
        if (arr[mid] == target) {
            ret = mid;
            rt = mid - 1;
        } else if (arr[mid] > target) {
            rt = mid - 1;
        } else if (arr[mid] < target) {
            lt = mid + 1;
        }
    }
    return ret;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, target;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for (int i = 0; i < m; ++i) {
        cin >> target;
        cout << Bin(0, n - 1, target) << '\n';
    }
}