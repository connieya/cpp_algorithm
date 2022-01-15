#include "bits/stdc++.h"

using namespace std;

int arr[1000];
int dp[1000];
int v[1000];

void func(int idx) {
    if (idx == -1) {
        return;
    }
    func(v[idx]);
    cout << arr[idx] << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int max = 0;
    int idx = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        v[i] = -1;
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                v[i] = j;
            }
        }
        if (dp[i] > max) {
            max = dp[i];
            idx = i;
        }
    }
    cout << max << '\n';
    func(idx);
}