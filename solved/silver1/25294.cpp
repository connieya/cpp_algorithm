//
// Created by 82109 on 2022-06-19.
//

#include "bits/stdc++.h"

using namespace std;

int arr[10000][10000];

void solve(int n) {
    int nCounter = 0;
    int x = 0, y = -1;
    int dir = 1;
    for (int nLength = 2 * n - 1; nLength > 0; nLength -= 2) {
        for (int i = 0; i < nLength; i++) {
            if (i < nLength / 2 + 1) {
                y += dir;
            } else {
                x += dir;
            }
            arr[x][y] = ++nCounter;
        }
        dir = -dir;
    }
}

void solve1(int x, int y) {
    cout << arr[x - 1][y - 1] << '\n';
}

void solve2(int x, int n) {
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (flag) break;
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == x) {
                cout << i + 1 << ' ' << j + 1 << '\n';
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, x, a, b, c;
    cin >> q;
    while (q--) {
        cin >> x >> a;
        solve(a);
        if (x == 1) {
            cin >> b >> c;
            solve1(b, c);
        } else {
            cin >> b;
            solve2(b, a);
        }
    }
}