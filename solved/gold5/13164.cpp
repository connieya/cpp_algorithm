#include "bits/stdc++.h"

using namespace std;

int arr[300001];
int n,m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> d;
    for (int i = 0; i < n-1; ++i) {
        d.push_back(arr[i+1]-arr[i]);
    }
    sort(d.begin(), d.end());
    long long ans = 0;
    for (int i = 0; i < n-m; ++i) {
        ans += d[i];
    }
    cout << ans;
}