#include "bits/stdc++.h"

using namespace std;

void print(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0) {
                cout << "(" << i << "," << j << ")" << '\n';
            } else if (i % 2 == 0) {
                if (j == m - 1)continue;
                cout << "(" << i << "," << j + 1 << ")" << '\n';
            } else if (i % 2 == 1) {
                if (j == m - 1) continue;
                cout << "(" << i << "," << m - j - 1 << ")" << '\n';
            }
        }
    }
    for (int i = n - 1; i > 0; --i) {
        cout << "(" << i << "," << 0 << ")" << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << 1 << '\n';
        print(n, m);
    }
}