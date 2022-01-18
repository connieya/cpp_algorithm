#include "bits/stdc++.h"

using namespace std;

long long arr[117];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    arr[1] = arr[2] = arr[3] = 1;
    int n;
    cin >> n;
    for (int i = 4; i <= n; ++i) {
        arr[i] = arr[i-1] + arr[i-3];
    }
    cout << arr[n];
}