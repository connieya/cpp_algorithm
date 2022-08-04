#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,l,r,x;
    cin >> n >> l >> r >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 3; i < 1<<n; ++i) {
        int sum = 0,cnt=  0;
        int mn = INT_MAX , mx = 0;
        for (int j = 0; j < n; ++j) {
            if(i & 1 << j){
                sum += arr[j];
                mn = min(arr[j],mn);
                mx = max(arr[j],mx);
                cnt++;
            }
        }
        if(cnt > 1 && sum >= l && sum <= r && (mx-mn) >=x) ans++;
    }
    cout << ans;
}