#include "bits/stdc++.h"

using namespace std;

int board[3][3];
int temp[3][3];
int arr[9];

bool isMagicSquare() {
    int magic = temp[0][0] + temp[0][1] + temp[0][2];
    for (int i = 1; i < 3; ++i) {
        if (magic != (temp[i][0] + temp[i][1] + temp[i][2])) return false;
    }
    for (int i = 0; i < 3; ++i) {
        if (magic != (temp[0][i] + temp[1][i] + temp[2][i])) return false;
    }
    if (magic != (temp[0][0] + temp[1][1] + temp[2][2])) return false;
    if (magic != (temp[0][2] + temp[1][1] + temp[2][0])) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < 9; ++i) {
        arr[i] = i + 1;
    }
    int ans = 80;
    do {
        for (int i = 0; i < 9; ++i) {
            temp[i / 3][i % 3] = arr[i];
        }
        int sum = 0;
        if (isMagicSquare()) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    sum += abs(temp[i][j] - board[i][j]);
                }
            }
            ans = min(sum, ans);
        }

    } while (next_permutation(arr, arr + 9));
    cout << ans;
}