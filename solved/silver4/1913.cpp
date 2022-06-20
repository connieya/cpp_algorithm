#include "bits/stdc++.h"

using namespace std;

int arr[1000][1000];
int n, target;
int nx, ny;
void solve() {
    int counter = n * n;
    int x = -1;
    int y = 0;
    int dir = 1;
    for (int nLength = 2 * n - 1; nLength > 0; nLength -= 2) {
        for (int i = 0; i < nLength; ++i) {
            if (i < nLength / 2 + 1) {
                x += dir;
            } else {
                y += dir;
            }
            arr[x][y] = counter--;
            if (arr[x][y] == target) {
                nx = x;
                ny = y;
            }
        }
        dir = -dir;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> target;
    solve();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << nx+1 << ' ' << ny+1;
}