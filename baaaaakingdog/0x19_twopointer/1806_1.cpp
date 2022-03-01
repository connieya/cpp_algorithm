#include "bits/stdc++.h"

using namespace std;

int arr[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n ,s;
    cin >> n >> s;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum < s){
        cout << 0;
        return 0;
    }
    sum = arr[0];
    int rt = 0;
    int ans = 0x7fffffff;
    for (int lt = 0; lt < n; ++lt) {
        while (rt < n && sum < s){
            rt++;
            if (rt < n) sum += arr[rt];
        }
        if (rt==n) break;
        ans = min(ans ,rt-lt+1);
        sum -= arr[lt];
    }
    cout << ans;
}