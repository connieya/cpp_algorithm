#include "bits/stdc++.h"

using namespace std;

int arr[100000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int left = 0;
    int right = n - 1;
    long long ans = abs(arr[left] + arr[right]);
    int a = arr[left], b = arr[right];
    while (left < right) {
        long long sum = arr[left] + arr[right];
        if (abs(sum) < ans) {
            ans = abs(sum);
            a = arr[left];
            b = arr[right];
        }
        if (sum > 0) {
            right--;
        } else {
            left++;
        }
    }
    cout << a << ' ' << b;
}