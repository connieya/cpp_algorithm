#include "bits/stdc++.h"

using namespace std;

int arr[101][101];
int number[101];
int row = 3, column = 3;

void calcRow() {
    int mx = -1;
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= column; ++j) {
            number[arr[i][j]]++;
        }
        int idx = 1;
        for (int cnt = 1; cnt <= 100; ++cnt) {
            for (int k = 1; k <= 100; ++k) {
                if (number[k] == cnt) {
                   arr[i][idx++] = k;
                   arr[i][idx++] = cnt;
                   number[k] = 0;
                }
            }
        }
        for (int j = idx; j < 101; ++j) {
            arr[i][j] = 0;
        }
        mx = max(idx-1, mx);
    }
    column = mx;
}

void calcColumn() {
    int mx = -1;
    for (int i = 1; i <= column; ++i) {
        for (int j = 1; j <= row; ++j) {
            number[arr[j][i]]++;
        }
        int idx =1;
        for (int cnt = 1; cnt <= 100; ++cnt) {
            for (int k = 1; k <= 100; ++k) {
                if (number[k] == cnt) {
                    arr[idx++][i] = k;
                    arr[idx++][i] = cnt;
                    number[k] = 0;
                }
            }
        }
        for (int j = idx; j < 101; ++j) {
            arr[j][i] = 0;
        }
        mx = max(idx-1, mx);

    }
    row = mx;
}

void print() {
    cout << "row : " << row << " column : " << column << '\n';
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= column; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
     cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r, c, k, ans = 0;
    cin >> r >> c >> k;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cin >> arr[i][j];
        }
    }
    while (arr[r][c] != k) {
        if (row >= column) {
            calcRow();
        } else {
            calcColumn();
        }
        ans++;
        if (ans > 100) {
            ans = -1;
            break;
        }
    }
    cout << ans;
}