#include "bits/stdc++.h"

using namespace std;

int arr[1000001];
int dp[1000002];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , size =1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dp[size] = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > dp[size]){
            size++;
            dp[size] = arr[i];
            continue;
        }

    }
}

