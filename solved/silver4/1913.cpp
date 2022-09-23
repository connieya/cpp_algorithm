#include "bits/stdc++.h"

using namespace std;
int arr[1000][1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int num = n * n;
    pair<int, int> ans;
    int k = 1;
    int x = -1, y = 0;
    for (int i = 2 * n - 1; i > 0; i -= 2) {
        for (int j = 0; j < i; ++j) {
            if (j < i / 2 + 1) x += k;
            else y += k;
            arr[x][y] = num--;
            if (arr[x][y] == m) {
                ans.first = x + 1;
                ans.second = y + 1;
            }
        }
        k = -k;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << ans.first << ' ' << ans.second;
}