#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i * i <= n; ++i) {
        if (i * i == n) {
            cout << 1;
            exit(0);
        }
    }
    for (int i = 1; i * i <= n; ++i) {
        for (int j = i; j * j <= n; ++j) {
            if (i * i + j * j == n) {
                cout << 2;
                exit(0);
            }
        }
    }
    for (int i = 1; i * i <= n; ++i) {
        for (int j = i; j * j <= n; ++j) {
            for (int k = j; k * k <= n; ++k) {
                if (i * i + j * j + k * k == n) {
                    cout << 3;
                    exit(0);
                }
            }
        }
    }
    cout << 4;
}