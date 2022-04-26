#include "bits/stdc++.h"

using namespace std;

int arr[1000][1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, target, x = -1, y = 0;
    int nx, ny;
    cin >> n >> target;
    int nCounter = n * n, nDirection = 1;
    for (int nLength = 2 * n - 1; nLength > 0; nLength -= 2) {
        for (int i = 0; i < nLength; ++i) {
            if (i < nLength / 2 + 1) x += nDirection;
            else y += nDirection;
            arr[x][y] = nCounter--;
            if (arr[x][y] == target) {
                nx = x, ny = y;
            }
        }
        nDirection = -nDirection;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << nx + 1 << ' ' << ny + 1;
}