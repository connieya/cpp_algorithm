#include "bits/stdc++.h"

using namespace std;

int n, m, r, md;
int arr[301][301];

void rotate(int x1, int x2, int y1, int y2) {
    int tmp = arr[x1][y1];

    for (int i = y1; i < y2; ++i) {
        arr[x1][i] = arr[x1][i + 1];
    }
    for (int i = x1; i < x2; ++i) {
        arr[i][y2] = arr[i + 1][y2];
    }
    for (int i = y2; i > y1; --i) {
        arr[x2][i] = arr[x2][i - 1];
    }
    for (int i = x2; i > x1; --i) {
        arr[i][y1] = arr[i - 1][y1];
    }

    arr[x1 + 1][y1] = tmp;
}

void rotate(int r) {
    int x1 = 0;
    int x2 = n - 1;
    int y1 = 0;
    int y2 = m - 1;
    while (x1 < x2 && y1 < y2) {
        for (int i = 0; i < r % ((x2 - x1 + y2 - y1) * 2); ++i) {
            rotate(x1, x2, y1, y2);
        }
        x1++;
        x2--;
        y1++;
        y2--;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> r;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
    rotate(r);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}