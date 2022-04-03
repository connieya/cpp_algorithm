#include "bits/stdc++.h"

using namespace std;

int arr[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    long long lt = 0;
    long long rt = 1e12 +1;
    long long ans;
    while (lt <= rt) {
        long long mid = (lt+rt)/2;
        long long cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += mid/arr[i];
        }
        if (cnt >= m){
            rt = mid-1;
            ans = mid;
        }else {
            lt = mid+1;
        }
    }
    cout << ans;
}