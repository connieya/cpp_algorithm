#include "bits/stdc++.h"

using namespace std;

int arr[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n ,b,c;
    cin >> n;
    long long ans = n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> b >> c;
    for (int i = 0; i < n; ++i) {
        arr[i] -= b;
        if (arr[i] <= 0) continue;
        ans += (arr[i] % c == 0) ? arr[i] / c  : arr[i]/c +1;
    }
    cout << ans;
}