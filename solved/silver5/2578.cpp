#include "bits/stdc++.h"

using namespace std;

int board[5][5];
int a[5];
int b[5];
int c, d;

bool solve(int num) {
    bool flag = false;
    for (int i = 0; i < 5; ++i) {
        if (flag) break;
        for (int j = 0; j < 5; ++j) {
            if (num == board[i][j]) {
                a[i]++;
                b[j]++;
                if (i == j) c++;
                if (i + j == 4) d++;
                flag = true;
                break;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < 5; ++i) {
        cnt += (a[i] == 5);
        cnt += (b[i] == 5);
    }
    cnt += (c == 5);
    cnt += (d == 5);
    return cnt >= 3;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> board[i][j];
        }
    }
    int num;
    for (int i = 1; i <= 25; ++i) {
        cin >> num;
        if (solve(num)) {
            cout << i;
            exit(0);
        }
    }
}