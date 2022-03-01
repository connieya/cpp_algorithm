#include "bits/stdc++.h"

using namespace std;

int arr[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, S;
    cin >> N >> S;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum < S) {
        cout << 0;
        return 0;
    }
    int lt = 0;
    int rt = 0;
    sum = arr[0];
    int ans = INT_MAX;
    while (rt < N) {
        if (sum < S) {
            rt++;
            sum += arr[rt];
        } else {
            ans = min(ans, rt - lt);
            sum -= arr[lt];
            lt++;
        }
    }
    cout << ans + 1;
}