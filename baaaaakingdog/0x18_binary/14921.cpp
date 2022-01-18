#include "bits/stdc++.h"

using namespace std;
const int MX = 1e5;
int arr[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int left = 0 , right = n-1;
    long long sum = arr[left]+arr[right];
    while (left < right) {
        long long ans = arr[left]+arr[right];
        if (abs(sum) > abs(ans)) {
            sum = ans;
        }
        if (ans > 0) {
            right--;
        }else {
            left++;
        }
    }
    cout << sum;
}