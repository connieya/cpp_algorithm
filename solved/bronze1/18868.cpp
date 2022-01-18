#include "bits/stdc++.h"

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pair<int, int> arr[10][100];
    int m, n, value;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> value;
            arr[i][j] = {value, j};
        }
        sort(arr[i], arr[i] + n);
    }
    int cnt = 0;
    bool isSame = true;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            isSame = true;
            for (int k = 0; k < n; ++k) {
                if (arr[i][k].second != arr[j][k].second) {
                    isSame = false;
                    break;
                }
            }
            if (isSame) cnt++;
        }
    }
    cout << cnt;
}