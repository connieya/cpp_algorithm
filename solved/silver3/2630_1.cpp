﻿#include "bits/stdc++.h"

using namespace std;

int white;
int blue;
int paper[129][129];

void func(int x, int y, int n) {
    int val = paper[x][y];
    for (int i = x; i < n + x; ++i) {
        for (int j = y; j < n + y; ++j) {
            if (val != paper[i][j]) {
                val = -1;
                break;
            }
        }
        if (val == -1) break;
    }
    if (val == 0) white++;
    else if (val == 1) blue++;
    else {
        func(x, y, n / 2);
        func(x + n / 2, y + n / 2, n / 2);
        func(x+ n / 2, y, n / 2);
        func(x, y+n/2, n / 2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> paper[i][j];
        }
    }
    func(0, 0, n);
    cout << white << '\n' << blue;


}