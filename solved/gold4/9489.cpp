#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    while (1) {
        int arr[1001] = {-1,}, child[1001] = {-1,};
        int idx, parent = -1, ans = 0;
        cin >> n >> m;
        if (!n && !m) break;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            if (arr[i] == m) idx = i;
            if (arr[i] != arr[i - 1] + 1) parent++;
            child[i] = parent;
        }

        for (int i = 1; i <= n; i++) {
            if (child[i] != child[idx] && child[child[i]] == child[child[idx]]) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}