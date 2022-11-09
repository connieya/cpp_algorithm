#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, res =0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end(), greater<int>());
    for (int i = 0; i < n; ++i) {
        res = max(res, arr[i]*(i+1));
    }
    cout << res;
}