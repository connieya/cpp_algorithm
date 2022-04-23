#include "bits/stdc++.h"

using namespace std;

int arr[502][2];
int dp[502][502];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i][0] >> arr[i][1];
    }
    for (int i = 1; i < n; ++i) {
        dp[i][i + 1] = arr[i][0] * arr[i][1] * arr[i + 1][1];
    }

}