#include "bits/stdc++.h"

using namespace std;

int arr[101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int ans = -100000;
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += arr[i];
    }
    for (int i = k; i <= n; ++i) {
        ans = max(sum,ans);
        sum += arr[i];
        sum -= arr[i-k];
    }
    cout << ans;
}