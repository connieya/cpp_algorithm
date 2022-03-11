#include "bits/stdc++.h"

using namespace std;

int arr[40001];
int dp[40001];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n ,it;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    int size = 1;
    for (int i = 2; i <= n; ++i) {
        if (arr[i] > dp[size]){
            size++;
            dp[size] = arr[i];
            continue;
        }
        it = lower_bound(dp+1,dp+size+1,arr[i])-dp;
        dp[it] = arr[i];
    }
    cout << size;
}