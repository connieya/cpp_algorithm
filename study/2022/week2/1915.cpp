#include "bits/stdc++.h"

using namespace std;

int arr[1001][1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m , ans =0;
    char s[1001];
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        for (int j = 0; s[j]; ++j) {
            arr[i][j+1] = s[j] - '0';
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (arr[i][j]) {
                arr[i][j] = min(arr[i - 1][j], min(arr[i - 1][j - 1], arr[i][j - 1])) + 1;
                ans = max(arr[i][j] , ans);
            }
        }
    }
    cout << ans * ans;
}