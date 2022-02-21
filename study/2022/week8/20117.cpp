#include "bits/stdc++.h"

using namespace std;

int arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int ans = 0;
    int i;
    for (i = n-1; i >= (n+1)/2 ; --i) {
        ans += arr[i]*2;
    }
    if (n%2==1){
        ans += arr[i];
    }
    cout << ans;
}