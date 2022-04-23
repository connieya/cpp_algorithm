#include "bits/stdc++.h"

using namespace std;

int arr[21];
int n, k;
int sum = 0, ans;

void dfs(int L, int start, int energy) {
    if (L > n) {
        ans = max(ans, energy);
        return;

    }
    sum = 0;
    for (int i = start; i < n; ++i) {
        sum += arr[i];
        if (sum >= k) {
            dfs(L + 1, i + 1, energy + sum - k);
        }
    }
    dfs(L + 1, start + 1, energy);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dfs(0, 0, 0);
    cout << ans;


}