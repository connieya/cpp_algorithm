#include "bits/stdc++.h"

using namespace std;

int arr[300001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int cnt = n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        if (arr[i] == cnt) cnt--;
    }
    cout << cnt;
}