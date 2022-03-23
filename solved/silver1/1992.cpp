#include "bits/stdc++.h"

using namespace std;
char arr[65][65];
void dq(int n, int x, int y) {
    char val = arr[x][y];
    for (int i = x; i < n + x; ++i) {
        for (int j = y; j < n + y; ++j) {
            if (val != arr[i][j]) {
                val = '2';
                break;
            }
        }
        if (val == '2') break;
    }

    if (val == '2') {
        cout << "(";
        dq(n / 2, x, y);
        dq(n / 2, x, y + n / 2);
        dq(n / 2, x + n / 2, y);
        dq(n / 2, x + n / 2, y + n / 2);
        cout << ")";
    } else {
        cout << val;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dq(n, 0, 0);

}