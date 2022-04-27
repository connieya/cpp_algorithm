#include "bits/stdc++.h"

using namespace std;

int arr[1001];

int countDvd(int mid ,int n){
    int sum = 0;
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        if (sum+arr[i] > mid){
            sum = arr[i];
            cnt++;
        }else {
            sum += arr[i];
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,ans, mx = INT_MIN;
    cin >> n >> m;
    int lt = 1 , rt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        rt += arr[i];
        if (arr[i] > mx){
            mx =arr[i];
        }
    }
    while (lt <= rt) {
        int mid = (lt+rt)/2;
        if (mid >= mx &&countDvd(mid,n) <= m){
            rt = mid-1;
            ans = mid;
        }else {
            lt = mid+1;
        }
    }
    cout << ans;

}