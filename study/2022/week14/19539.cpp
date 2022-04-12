#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, height, x, y;
    cin >> n;
    x = y = 0;
    for (int i = 0; i < n; ++i) {
        cin >> height;
        x += (height / 2);
        y += height;
    }
    if (y % 3 != 0) {
        cout << "NO";
    } else {
        y = y / 3;
        if (x >= y) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }


}