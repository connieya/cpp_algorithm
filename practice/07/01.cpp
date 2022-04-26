#include "bits/stdc++.h"

using namespace std;

int arr[46];
int n;
int ans = INT_MAX;

void dfs(int L, int cost) {
    if (L >= n) {
        ans = min(ans, cost);
        return;
    }
    dfs(L + 1, cost + arr[L]);
    dfs(L + 2, cost + arr[L + 1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dfs(0, 0);
    cout << ans;
}