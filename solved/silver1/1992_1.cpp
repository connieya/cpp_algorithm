#include "bits/stdc++.h"

using namespace std;

char board[65][65];

void divide_conquer(int n, int x, int y) {
    char first = board[x][y];
    for (int i = x; i < x + n; ++i) {
        for (int j = y; j < y + n; ++j) {
            if (first != board[i][j]) {
                first = '2';
                break;
            }
            if (first == '2') break;
        }
    }
    if (first == '2') {
        cout << "(";
        divide_conquer(n / 2, x, y);
        divide_conquer(n / 2, x, y + n / 2);
        divide_conquer(n / 2, x + n / 2, y);
        divide_conquer(n / 2, x + n / 2, y + n / 2);
        cout << ")";
    } else {
        cout << first;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }
    divide_conquer(n, 0, 0);
}