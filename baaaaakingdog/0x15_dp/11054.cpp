#include "bits/stdc++.h"

using namespace std;

int arr[1001];
int dp1[1001];
int dp2[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        dp1[i] = 1;
        for (int j = i - 1; j >= 0; --j) {
            if (arr[i] > arr[j] && dp1[i] < dp1[j] + 1) {
                dp1[i] = dp1[j] + 1;
            }
        }
    }
    for (int i = n-1; i >=0; --i) {
        dp2[i] = 1;
        for (int j = i+1; j <n ; ++j) {
            if(arr[i] > arr[j] && dp2[i] < dp2[j]+1) {
                dp2[i] = dp2[j]+1;
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if(dp1[i]+dp2[i]-1 > ans){
            ans = dp1[i]+dp2[i]-1;
        }
    }
    cout << ans;
}