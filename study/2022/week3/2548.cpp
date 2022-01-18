#include "bits/stdc++.h"

using namespace std;

int arr[20001];
int n;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int ans = n % 2 == 1 ? arr[(n + 1) / 2 + -1] : arr[n / 2 - 1];
    cout << ans;
}