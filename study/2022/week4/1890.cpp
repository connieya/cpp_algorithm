#include "bits/stdc++.h"

using namespace std;

int board[101][101];
long long tmp[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    int jump = board[0][0];
    if (jump < n) {
        tmp[jump][0] = 1;
        tmp[0][jump] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == n - 1 && j == n - 1) break;
            if (tmp[i][j] > 0) {
                jump = board[i][j];
                if (jump + i < n) {
                    tmp[jump + i][j] += tmp[i][j];
                }
                if (jump + j < n) {
                    tmp[i][jump + j] += tmp[i][j];

                }
            }
        }
    }
    cout << tmp[n - 1][n - 1];
}